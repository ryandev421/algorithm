class Solution {
public:
    string addBoldTag(string s, vector<string>& dict)
    {
        string res;
        int n = s.length();
        vector<int> check (n + 1, 0);
        
        for (int i = 0; i < dict.size(); i++) {
            kmp(s, dict[i], check);
        }
        for (int i = 0, count = 0; i < s.length(); i++) {
            if (count > 0 && count + check[i] == 0) {
                res += "</b>";
            }
            if (check[i] > 0 && count == 0) {
                res += "<b>";
            }
            res += s[i];
            count += check[i];
        }
        if (check[n] < 0) res += "</b>";
        
        return res;
    }
    
    void kmp(const string& s, const string& dict_s, vector<int>& check)
    {
        int m = dict_s.length();
        vector<int> pi = getPi(dict_s);
        
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            while (j > 0 && dict_s[j] != s[i]) {
                j = pi[j-1];
            }
            if (dict_s[j] == s[i]) {
                j++;
                if (j == m) {
                    check[i-m+1]++;
                    check[i+1]--;
                    j = pi[j-1];
                }
            }
        }
    }
    
    vector<int> getPi(const string& s)
    {
        int n = s.length();
        vector<int> pi(n, 0);
        
        int j = 0;
        for (int i = 1; i < s.length(); i++) {
            while (j > 0 && s[j] != s[i]){
                j = pi[j-1];
            }
            if (s[j] == s[i]) pi[i] = ++j;
        }
        return pi;
    }
};