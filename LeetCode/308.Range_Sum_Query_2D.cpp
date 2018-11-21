class IndexTree {
private:
    int offset;
    int *tree;
public:
    IndexTree(int n) {
        for (offset = 1; offset < n; offset <<= 1);
        tree = new int[offset<<1];
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

class NumMatrix {
private:
    vector<IndexTree> m_square_sum;
    vector<vector<int>> m_matrix;
public:
    
    NumMatrix(vector<vector<int>> matrix) {
        m_matrix = matrix;
        if (matrix.size() == 0) {
            return;
        }
        int row_sum[matrix[0].size()] = {0};
        for (int i = 0; i < matrix.size(); ++i) {
            for (int p = 0; p < matrix[i].size(); ++p) {
                row_sum[p] += matrix[i][p];
            }
            IndexTree tree_sum((int)matrix[i].size());
            for (int p = 0; p < matrix[i].size(); ++p) {
                tree_sum.update(p, row_sum[p]);
            }
            m_square_sum.push_back(tree_sum);
        }
    }
    
    void update(int row, int col, int val) {
        m_matrix[row][col] = val;
        int upper_row_sum = (row != 0) ? m_square_sum[row - 1].query(col, col) : 0;
        for (int i = row; i < m_matrix.size(); ++i) {
            m_square_sum[i].update(col, upper_row_sum + m_matrix[i][col]);
            upper_row_sum += m_matrix[i][col];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum1 = (row1 != 0) ? m_square_sum[row1 - 1].query(col1, col2) : 0;
        int sum2 = m_square_sum[row2].query(col1, col2);
        
        return (sum2 - sum1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */