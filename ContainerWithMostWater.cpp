class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        for (int l = 0, r = height.size()-1; r > l; ) {
            if (height[l] > height[r])
                max_area = max(max_area, (r-l)*height[r--]);
            else
                max_area = max(max_area, (r-l)*height[l++]);
        }
        return max_area;
    }
};
