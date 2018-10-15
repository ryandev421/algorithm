class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dy(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];
                int length = word.length();
                if (i+1 - length < 0) continue;
                if (i+1 != length && dy[i-length] == false) continue;
                
                int k;
                for (k=0;k<length;k++) {
                    if (word[k] != s[i-length+1+k]) break;
                }
                if (k==length) {
                    dy[i] = true;
                    break;
                }
            }
        }
        return dy[s.size()-1];
    }
};
