class Solution {
public:
    int n, m;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size();
        if (n > 0) {
            m = matrix[0].size();
        }
        
        int y = 0, x = m - 1;
        while (y < n && x >=0) {
            if (matrix[y][x] < target) {
                y++;
            } else if (matrix[y][x] > target) {
                x--;
            } else {
                return true;
            }
        }
        return false;
    }
};