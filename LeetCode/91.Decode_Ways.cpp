class Solution {
public:
    int numDecodings(string s) {
        vector<int> dy(s.size(), 0);
        dy[0] = (s[0] != '0') ? 1 : 0;
        for (int i = 1; i < s.size(); i++) {
            dy[i] = (s[i] != '0') ? dy[i-1] : 0;
            if (s[i-1] == '1' || (s[i-1] =='2' && s[i]<='6')) {
                dy[i] += (i != 1) ? dy[i-2] : 1;
            }
        }
        return dy[s.size() - 1];
    }
};
