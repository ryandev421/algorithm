struct RAIN
{
    int le, ri;
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<RAIN> dy(n);
        int res = 0;
        
        int max_h = 0;
        for (int i = 0; i< n; i++) {
            dy[i].le = max_h;
            max_h = max(max_h, height[i]);
        }
        max_h = 0;
        for (int i = n-1; i >= 0; i--) {
            dy[i].ri = max_h;
            max_h = max(max_h, height[i]);
        }
        for (int i = 0; i< n; i++) {
            int h = min(dy[i].le, dy[i].ri);
            if (h > height[i]) res += h - height[i];
        }
        
        return res;
    }
};