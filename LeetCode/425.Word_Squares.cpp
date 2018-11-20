class Solution {
public:
    vector<vector<string>> res;
    map<string, vector<string>> hash_map;
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<string> ans;
        
        if (words.size() == 0) {
            return res;
        }
        for (string s : words) {
            for (int i = 0; i < s.length(); i++ ){
                hash_map[s.substr(0, i + 1)].push_back(s);
            }
        }
        
        for (string s : words) {
            ans.push_back(s);
            makeSquare(ans, words, 1);
            ans.pop_back();
        }
        
        return res;
    }
    
    void makeSquare(vector<string>& ans, const vector<string>& words, int index)
    {
        if (index == words[0].length()) {
            res.push_back(ans);
            return ;
        }
        string prefix;
        for (int i = 0; i < index; i++) {
            prefix += ans[i][index];
        }
        for (string word : hash_map[prefix]) {
            ans.push_back(word);
            makeSquare(ans, words, index+1);
            ans.pop_back();
        }
    }
};