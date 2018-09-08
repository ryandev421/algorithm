class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k==0) return 0;
        
        int countOfChar[255] = {0};
        int count = 0;
        int res = 0;
        int le=0,ri=0;
        for(;ri < s.length(); ++ri) {
            if (countOfChar[(int)s[ri]] == 0) {
                if (count==k) break;
                count++;
            }
            countOfChar[(int)s[ri]]++;
        }
        res = ri-le;

        for(;ri < s.length(); ++ri) {
            if (countOfChar[(int)s[ri]] == 0) {
                count++;
            }
            countOfChar[(int)s[ri]]++;
            if (count<=k){
                res = max(res, ri-le+1);
                continue;
            }
            
            while(count > k) {
                countOfChar[(int)s[le]]--;
                if (countOfChar[(int)s[le]] == 0) {
                    count--;
                }
                le ++;
            }
            res = max(res, ri-le+1);
        }
        return res;
    }
};
