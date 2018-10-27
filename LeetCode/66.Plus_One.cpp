class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0){            
            digits.push_back(1);
        } else { 
            digits[digits.size()-1]++;
            for(int i = digits.size() - 1;i >= 0; --i) {
                if(digits[i] > 9) {
                    digits[i] = digits[i] % 10;
                    if(i!=0) {
                        digits[i-1] = digits[i-1] + 1;   
                    } else {
                        digits.insert(digits.begin(),1);
                    }
                }         
            }
        }
       return digits;
    }
};