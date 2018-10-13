class Solution {
public:
    int minDistance(string word1, string word2) {
        int length_1 = word1.length();
        int length_2 = word2.length();
        int dy[length_1+1][length_2+1] = {0};
        for (int i = 0; i <= length_2; i++) dy[0][i] = i;
        for (int i = 0; i <= length_1; i++) dy[i][0] = i;
        
        for (int i = 1; i<= length_1; i++) {
            for (int j = 1; j<= length_2; j++) {
                dy[i][j] = min(dy[i-1][j], dy[i][j-1]) + 1;
                
                if (word1[i-1] == word2[j-1]) {
                    dy[i][j] = min(dy[i][j], dy[i-1][j-1]);
                } else {
                    dy[i][j] = min(dy[i][j], dy[i-1][j-1] + 1);
                }
            }
        }
        return dy[length_1][length_2];
    }
};
