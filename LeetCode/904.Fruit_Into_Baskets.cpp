class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size();
        vector<int> fruit_count(n, 0);
        int res = 0;
        int count = 0;
        for (int le=0,ri=0; ri < n; ri++) {
            int ri_index = tree[ri];
            if (fruit_count[ri_index]==0) {
                count++;
            }
            fruit_count[ri_index]++;
            while(count > 2) {
                int le_index = tree[le];
                fruit_count[le_index]--;
                if (fruit_count[le_index]==0) {
                    count--;
                }
                le++;
            }
            res = max(res, ri-le+1);
        }
        return res;
    }
};