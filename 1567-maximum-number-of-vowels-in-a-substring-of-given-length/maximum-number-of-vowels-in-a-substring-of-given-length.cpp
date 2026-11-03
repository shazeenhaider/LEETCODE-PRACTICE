class Solution {
public:
    int maxVowels(string s, int k) {
        //fixed size sliding window question
        int left=0;
        int currCount=0;
        int maxCount=0;
        for(int right=0; right<s.size();right++){
            if(right-left+1>k){
                //shrink the substring
                if (s[left] == 'a' || s[left] == 'e' || s[left] == 'i' ||
                s[left] == 'o' || s[left] == 'u') {
                 currCount--;
                }
                left++;
            }
            if(s[right]=='a'|| s[right]=='e'|| s[right]=='i'|| s[right]=='o'|| s[right]=='u'){
            currCount++;
            }
            maxCount=max(currCount,maxCount);
        }
     return maxCount;
    }
};