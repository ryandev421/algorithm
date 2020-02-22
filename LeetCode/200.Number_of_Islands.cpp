class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    int island_count = 0;
    int dir[4][2] = {
            {-1, 0}, {0, +1},
            {+1, 0}, {0, -1}
    };

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        if (n > 0) {
            m = grid[0].size();
        }
        for (int i = 0; i < n; i++) {
            vector<bool> init_visited(m, false);
            visited.push_back(init_visited);
        }

        for (int i = 0; i < n; i++) {
            for (int j =0; j < m; j++) {
                if (visited[i][j]) continue;
                if (grid[i][j]=='0') continue;
                scanIsland(i, j, grid);
                island_count++;
            }
        }
        return island_count;
    }

    void scanIsland(int y, int x, vector<vector<char>>& grid) {
        visited[y][x] = true;
        for (int k = 0; k < 4; k++) {
            int ey = y + dir[k][0];
            int ex = x + dir[k][1];
            if (!isWall(ey, ex) && grid[ey][ex] == '1' && !visited[ey][ex]) {
                scanIsland(ey, ex, grid);
            }
        }
    }

    bool isWall(int y, int x) {
        return !(y >= 0 && x >=0 && y < n && x < m);
    }
};