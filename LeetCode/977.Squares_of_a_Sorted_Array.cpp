class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        int p1 = 0;
        int p2 = (int)A.size() - 1;
        
        while (p1<=p2) {
            int num1 = A[p1]*A[p1];
            int num2 = A[p2]*A[p2];
            if (num1 >= num2) {
                res.push_back(num1);
                p1++;
            } else {
                res.push_back(num2);
                p2--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};