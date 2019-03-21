class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_count++;
            } else {
                nums[i-zero_count] = nums[i];
            }
        }
        for (int i = 0; i < zero_count; i++) {
            nums[(int)nums.size()-1-i] = 0;
        }
    }
};