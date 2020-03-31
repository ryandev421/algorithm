class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int aStartRes = min(minDomino(A[0], A, B), minDomino(B[0], A, B));
        int bStartRes = min(minDomino(A[0], B, A), minDomino(B[0], B, A));
        int res = min (aStartRes, bStartRes);
        
        return res != INT_MAX ? res : -1;
    }
    
    int minDomino(int target, vector<int>& A, vector<int>&B) {
        int rotCount = 0;
        for (int pos = 0; pos < A.size(); pos++) {
            if (A[pos] != target) {
                if (B[pos] == target) {
                    rotCount ++;
                } else {
                    return INT_MAX;
                }
            }
        }
        return rotCount;
    }
};