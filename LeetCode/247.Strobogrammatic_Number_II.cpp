class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammatic(n, true);
    }
    
    vector<string> findStrobogrammatic(int n, bool is_first_recur) {
        vector<string> res;
        if (n == 0) {
            res.push_back("");
        } else if (n == 1) {
            if (!is_first_recur || (is_first_recur && n == 1)) res.push_back("0");
            res.push_back("1");
            res.push_back("8");
        } else {
            vector<string> sub_res = findStrobogrammatic(n-2, false);
            for (auto str : sub_res) {
                if (!is_first_recur) res.push_back("0" + str + "0");
                res.push_back("1" + str + "1");
                res.push_back("8" + str + "8");
                res.push_back("6" + str + "9");
                res.push_back("9" + str + "6");
            }
        }
        return res;
    }
};
