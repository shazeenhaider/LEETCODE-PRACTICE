class Solution {
public:
    int reverseDegree(string s) {
        int reverseDegree = 0;

        for(int i = 1; i <= s.length(); i++) {
            int Rindex = 'z' - s[i - 1] + 1;
            reverseDegree += Rindex * i;
        }

        return reverseDegree;
    }
};