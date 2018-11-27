class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;

        if (nums.size() == 0) {
            res.push_back(getRange(lower, upper));
        } else {
            int next = lower;
            for (int index = 0; index < nums.size(); ++index) {
                if (nums[index] < next) continue;
                if (next == nums[index]) {
                    if (next != std::numeric_limits<int>::max()) next ++;
                    continue;
                }

                res.push_back(getRange(next, nums[index] -1));
                if (nums[index] != std::numeric_limits<int>::max()) next = nums[index] + 1;
                else next = nums[index];
            }

            if (nums.back() < upper) {
                res.push_back(getRange(nums.back() + 1, upper));
            }
        }
        
        return res;
    }

    string getRange(int lower, int upper)
    {
        return (lower == upper) ? std::to_string(lower) : std::to_string(lower) + "->" + std::to_string(upper);
    }
};