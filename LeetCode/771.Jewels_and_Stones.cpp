class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        for (string::iterator it = S.begin(); it != S.end(); it++) {
            if (J.find(*it) != string::npos) {
                res ++;
            }
        }
        
        return res;
    }
};