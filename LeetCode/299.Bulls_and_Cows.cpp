class Solution {
public:
    string getHint(string secret, string guess) {
        int bull_cnt = getBullCount(secret, guess);
        int cow_cnt = getMatchedAlphabetCount(secret, guess) - bull_cnt;
        
        char res[20];
        sprintf(res, "%dA%dB", bull_cnt, cow_cnt);
        
        return res;
    }
    
    int getBullCount(string &secret, string &guess)
    {
        int bull_cnt = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bull_cnt ++;
            }
        }
        
        return bull_cnt;
    }
    
    int getMatchedAlphabetCount(string &secret, string &guess)
    {
        int res = 0;
        int secret_alpha_cnt[10] ={0};
        int guess_alpha_cnt[10] ={0};
        
        for (int i = 0; i < secret.length(); i++) {
            secret_alpha_cnt[secret[i]-'0']++;
        }
        for (int i = 0; i < guess.length(); i++) {
            guess_alpha_cnt[guess[i]-'0']++;
        }
        
        for (int i = 0; i < 10; i++) {
            res += min(secret_alpha_cnt[i], guess_alpha_cnt[i]);
        }
        
        return res;
    }
};