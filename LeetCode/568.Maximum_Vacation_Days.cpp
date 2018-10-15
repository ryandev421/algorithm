class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size();
        int m = days[0].size();
        int dy[m][n];
        int ans=0;
        
        for(int i = 0; i<m; i++) {
            for(int j=0;j<n;j++) {
                dy[i][j] = std::numeric_limits<int>::min();
            }
        }
        for(int i = 0; i < n; i++) {
            if (i==0 || flights[0][i]) {
                dy[0][i] = days[i][0];
                ans = max(ans, dy[0][i]);
            }
        }
        for (int i = 1; i < m;i++) {
            for (int j=0;j<n;j++) {
                for (int k=0;k<n;k++) {
                    if (dy[i-1][k] == std::numeric_limits<int>::min()) continue;
                    if (flights[k][j] || k==j) {
                        dy[i][j] = max(dy[i][j], dy[i-1][k] + days[j][i]);
                        ans = max(ans, dy[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};
