class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash_map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int num = target-nums[i];
            if (hash_map.find(num) != hash_map.end()) {
                res.push_back(hash_map[num]);
                res.push_back(i);
                break;
            }
            hash_map[nums[i]] = i;
        }
        return res;
    }
};