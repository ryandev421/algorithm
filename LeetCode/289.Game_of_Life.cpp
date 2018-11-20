class Solution {
public:
    int dir[8][2] = {
        {-1, -1}, {-1, 0}, {-1, +1},
        {0, -1}, {0, +1},
        {+1, -1}, {+1, 0}, {+1, +1}
    };
    void gameOfLife(vector<vector<int>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int y = i + dir[k][0];
                    int x = j + dir[k][1];
                    if (y < 0 || x < 0 || y >= board.size() || x >= board[i].size()) continue;
                    count += (board[y][x] & 1);
                }
                if (board[i][j] == 0 && count == 3) {
                    board[i][j] += 2;
                } else if (board[i][j] == 1 && (count == 2 || count == 3)) {
                    board[i][j] += 2;
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                board[i][j] = (board[i][j] >> 1);
            }
        }
    }
};