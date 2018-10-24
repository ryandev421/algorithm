class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        reverse(S.begin(), S.end());
        string res;
        bool is_first = true;
        
        for (int i = 0, count = 0; i < S.length(); i++) {
            if (S[i] == '-') continue;
            if (count == 0 && !is_first) {
                res += '-';
            }
            is_first = false;
            
            res += charToUpper(S[i]);
            count ++;
            if (count == K) {
                count =0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
    char charToUpper(char s) {
        if ('a' <= s && s <= 'z') return s -'a' + 'A';
        else return s;
    }
};


static const int _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();