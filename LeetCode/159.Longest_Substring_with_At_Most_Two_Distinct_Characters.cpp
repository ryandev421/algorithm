class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.length() == 0) return 0;
        
        int alphabet_count[52] = {0};
        int res = 0;
        int count = 0;
        for (int le=0,ri=0; ri<s.length();ri++) {
            int ri_index = getAlphaIndex(s[ri]);
            if (alphabet_count[ri_index]==0) {
                count++;
            }
            alphabet_count[ri_index]++;
            while(count > 2) {
                int le_index = getAlphaIndex(s[le]);
                alphabet_count[le_index]--;
                if (alphabet_count[le_index]==0) {
                    count--;
                }
                le++;
            }
            res = max(res, ri-le+1);
        }
        return res;
    }
    int getAlphaIndex(char s)
    {
        if ('a' <= s && s<='z') return s-'a';
        else return s-'A'+26;
    }
};