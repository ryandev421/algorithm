class Solution {
public:
    int n;
    vector<bool> banned;
    vector<vector<string>> ans;
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        n = products.size();
        banned.resize(n, false);
        ans.resize(searchWord.size());
        
        sort(products.begin(), products.end());
        
        for (int i = 0; i < searchWord.length(); i++) {
            for (int p = 0; p < products.size(); p++) {
                if (banned[p]) {
                    continue;
                }
                string product = products[p];
                if (product.length() < i + 1 || product[i] != searchWord[i]) {
                    banned[p] = true;
                } else {
                    if (ans[i].size() < 3) {
                        ans[i].push_back(product);
                    }
                }
            }
        }
        
        return ans;
    }
};