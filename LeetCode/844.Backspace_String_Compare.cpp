class Solution {
public:
    bool backspaceCompare(string S, string T) {
        S = getText(S);
        T = getText(T);
        
        return (S == T);
    }
    
    string getText(string s)
    {
        char text[s.length()+1] ={0};
        int text_cnt=0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i]=='#') {
                if (text_cnt!=0) text[--text_cnt] = '\0';
            } else {
                text[text_cnt++] = s[i];
            }
        }
        return string(text);
    }
};