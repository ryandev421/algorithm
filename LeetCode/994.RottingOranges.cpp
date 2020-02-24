class Solution {
public:
    int n, m;
    int dir[4][2] = {
        {-1, 0}, {0, +1}, {+1, 0}, {0, -1}
    };
    
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        if (n > 0) {
            m = grid[0].size();
        }
        
        int passed_time = 0;
        while(1) {
            if (!hasFreshOranges(grid)) {
                break;
            }
            bool is_changed = rottenOranges(grid);
            if (!is_changed) {
                break;
            }
            passed_time++;
            
        }
        return !hasFreshOranges(grid) ? passed_time : -1;
    }
    
    bool hasFreshOranges(const vector<vector<int>>& grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool rottenOranges(vector<vector<int>>& grid) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    for (int k = 0; k < 4; k++) {
                        int ey = i + dir[k][0];
                        int ex = j + dir[k][1];
                        if (ey < 0 || ex < 0 || ey >= n || ex >= m) continue;
                        if (grid[ey][ex] == 1) {
                            grid[ey][ex] = -1;
                        }
                    }
                }
            }
        }
        
        bool is_changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1) {
                    grid[i][j] = 2;
                    is_changed = true;
                }
            }
        }
        return is_changed;
    }
};