class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size();i++) {
            for (int j =0; j< grid[i].size();j++) {
                if (i==0 && j==0) continue;
                int num1 = (i!=0) ? grid[i-1][j] : std::numeric_limits<int>::max();
                int num2 = (j!=0) ? grid[i][j-1] : std::numeric_limits<int>::max();
                grid[i][j] += min(num1, num2);
            }
        }
        return grid.back().back();
    }
};
