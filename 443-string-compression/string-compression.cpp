class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int n = chars.size();

        while (j < n) {
            char ch = chars[j];
            int count = 0;

            while (j < n && chars[j] == ch) {
                count++;
                j++;
            }

            chars[i++] = ch;

            if (count > 1) {
                string s = to_string(count);

                for (char digit : s) {
                    chars[i++] = digit;
                }
            }
        }

        chars.resize(i);
        return chars.size();
    }
};