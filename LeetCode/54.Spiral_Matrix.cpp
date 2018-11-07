class Solution {
public:
    vector<int> res;
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r==0) return res;
        int w = matrix[0].size();
        int t = min(r, w);
        if (t%2==0) t /= 2;
        else t = t/2 +1;
        for (int i=0; i<t; i++) {
            trackSquare(matrix, i, i, r-i*2, w-i*2);
        }
        return res;
    }
    
    void trackSquare(const vector<vector<int>>& matrix, const int y, const int x, const int r, const int w)
    {
        int i;
        for (i = x; i <= x + w -1; i++) {
            res.push_back(matrix[y][i]);
        }
        if (r==1) return;
        for (i = y+1; i <= y+r -1; i++) {
            res.push_back(matrix[i][x+w-1]);
        }
        if (w==1) return ;
        for (i = x+w-2; i >= x; i--) {
            res.push_back(matrix[y+r-1][i]);
        }
        for (i = y+r-2; i>y; i--) {
            res.push_back(matrix[i][x]);
        }
    }
};