class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        radixSort(nums);
        int max = 0;
        for(int i=1;i<nums.size();i++) {
            if (nums[i] - nums[i-1] > max) {
                max = nums[i] - nums[i-1];
            }
        }
        return max;
    }
    
    void radixSort(vector<int>& arr)
    {
        int max_num = getMax(arr);
        
        for (int exp = 1; max_num/exp > 0; exp *= 10) {
            int count[10] = {0};
            for(int i = 0; i < arr.size(); i++) {
                count[(arr[i]/exp)%10]++;
            }
            for(int i = 1; i < 10; i++) {
                count[i] += count[i-1];
            }
            vector<int> output(arr.size());
            for (int i = (int)arr.size() - 1; i >= 0; i--) {
                output[--count[(arr[i]/exp)%10]] = arr[i];
            }
            for(int i = 0; i< arr.size(); i++) {
                arr[i] = output[i];
            }
        }
    }
    
    int getMax(vector<int>& arr)
    {
        int max = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
};
