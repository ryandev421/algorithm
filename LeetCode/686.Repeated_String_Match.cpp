class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int res = 0;
        string copied_str = "";
        while (copied_str.length() < B.length()) {
            res++;
            copied_str += A;
        }
        if (copied_str.find(B) != string::npos) {
            return res;
        } else {
            res++;
            copied_str += A;
            
            if (copied_str.find(B) != string::npos) {
                return res;
            } else {
                return -1;
            }
        }
    }
};
