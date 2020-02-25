class Solution {
public:
    int n;
    vector<vector<bool>> dy;
    
    string longestPalindrome(string s) {
        n = s.length();
        dy.resize(n);
        for (int i = 0; i< n; i++) {
            dy[i].resize(n, false);
        }
        
        int possible_pos = -1;
        int possible_length = -1;
        for (int p = 1; p <= n; p++) {
            for (int i = 0; i < n - p + 1; i++) {
                int j = i + p - 1;
                if (s[i] == s[j]) {
                    if (p <= 2) {
                        dy[i][j] = true;
                    } else {
                        dy[i][j] = dy[i][j] | dy[i + 1][j - 1];
                    }
                }
                if (dy[i][j]) {
                    possible_pos = i;
                    possible_length = p;
                }
            }
            
        }
        
        return possible_pos != -1 ? s.substr(possible_pos, possible_length) : "";
    }
};