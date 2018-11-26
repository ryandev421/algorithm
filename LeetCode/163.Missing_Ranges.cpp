class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        vector<long long> new_nums;
        
        new_nums.push_back((long long)lower - 1);
        new_nums.insert(new_nums.end(), nums.begin(), nums.end());
        new_nums.push_back((long long)upper + 1);
        
        for (int index = 1; index < new_nums.size(); ++index) {
            long long num1 = new_nums[index-1] + 1;
            long long num2 = new_nums[index] - 1;
            
            long long diff = num2 - num1 +1;
            if (diff <= 0) continue;
            else if(diff == 1) {
                res.push_back(std::to_string(num1));
            } else {
                res.push_back(std::to_string(num1) + "->" + std::to_string(num2));
            }
        }
        
        return res;
    }
};