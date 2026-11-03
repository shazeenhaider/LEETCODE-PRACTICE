
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int n = s.size();
        int wordLen = words[0].size();
        int totalWords = words.size();

        int windowSize = wordLen * totalWords;

        if (n < windowSize) {
            return ans;
        }

        // Store the required frequency of each word
        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try all possible starting positions within one word
        for (int start = 0; start < wordLen; start++) {

            unordered_map<string, int> window;

            int left = start;
            int matchedWords = 0;

            // Move right pointer word by word
            for (int right = start; right + wordLen <= n; right += wordLen) {

                string currentWord = s.substr(right, wordLen);

                // If the word is not required, reset the window
                if (required.find(currentWord) == required.end()) {

                    window.clear();
                    matchedWords = 0;

                    left = right + wordLen;
                    continue;
                }

                // Include current word
                window[currentWord]++;
                matchedWords++;

                // Remove extra occurrences
                while (window[currentWord] > required[currentWord]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    matchedWords--;

                    left += wordLen;
                }

                // Check whether all words are matched
                if (matchedWords == totalWords) {

                    ans.push_back(left);

                    // Remove the first word to continue searching
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    matchedWords--;

                    left += wordLen;
                }
            }
        }

        return ans;
    }
};
