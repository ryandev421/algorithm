class Solution {
public:
    int rob(vector<int>& nums) {
        int count_of_house = nums.size();
        
        if (count_of_house == 0) return 0;
        else if (count_of_house == 1) return nums[0];
        else {
            int dy[count_of_house][2] = {0};
            dy[0][0] = 0;
            dy[0][1] = nums[0];
            dy[1][0] = nums[1];
            dy[1][1] = nums[0];
            for (int i = 2; i < count_of_house; i++) {
                dy[i][0] = max(dy[i-1][0], dy[i-2][0] + nums[i]);
                dy[i][1] = max(dy[i-1][1], dy[i-2][1] + nums[i]);
            }
            return max(dy[count_of_house-1][0], dy[count_of_house-2][1]);
        }
    }
};
