class NumMatrix {
public:
    
    NumMatrix(vector<vector<int>> matrix) {
        
    }
    
    void update(int row, int col, int val) {
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
    }
};

class IndexTree {
private:
    int offset;
    int *tree;
public:
    IndexTree(int n) {
        for (offset = 1; offset < n; offset <<= 1);
        offset--;
        tree = new int[offset+1];
    }
    void update (int x, int val)
    {
        x |= offset;
        tree[x] = val;
        while (x >>= 1) {
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
        }
    }
    int query (int l, int r)
    {
        int l_val = 0, r_val = 0;
        l |= offset;
        r |= offset;
        while (l <=r) {
            if (l & 1) l_val += tree[l++];
            if (!(r & 1)) r_val += tree[r--];
            l >>= 1;
            r >>= 1;
        }
        return l_val + r_val;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */