class Solution {
public:
    string reverseVowels(string s) {
        int le = 0, ri = (int)s.length()-1;
        
        while (le < s.length() && ri >= 0 && le < ri) {
            if (is_vowel(s[le]) && is_vowel(s[ri])) {
                swap(s[le], s[ri]);
                le++;
                ri--;
                continue;
            }
            if (!is_vowel(s[le])) {
                le++;
            }
            if (!is_vowel(s[ri])) {
                ri--;
            }
        }
        return s;
    }
    
    bool is_vowel(char a) {
        string vowels = "aeiouAEIOU";
        return vowels.find(a) != string::npos;
    }
};