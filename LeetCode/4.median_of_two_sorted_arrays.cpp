class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArr;
        
        int x_idx=0, y_idx=0;
        while (x_idx < nums1.size() && y_idx < nums2.size()) {
            if (nums1[x_idx] < nums2[y_idx]) {
                sortedArr.push_back(nums1[x_idx++]);
            } else {
                sortedArr.push_back(nums2[y_idx++]);
            }
        }
        if (x_idx == nums1.size()) {
            while (y_idx < nums2.size()) {
                sortedArr.push_back(nums2[y_idx++]);
            }
        } else {
            while (x_idx < nums1.size()) {
                sortedArr.push_back(nums1[x_idx++]);
            }
        }
        int totalSize = sortedArr.size();
        if (totalSize%2 == 1) {
            return sortedArr[totalSize/2];
        } else {
            return (sortedArr[totalSize/2-1] + sortedArr[totalSize/2]) / 2.0;
        }
    }
};
