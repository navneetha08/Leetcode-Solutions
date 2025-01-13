class Solution {
public:
    int maxArea(vector<int>& height) {

        int max_area = 0;
        int n = height.size();
        int lo = 0; int hi = n-1; int area;

        while (lo < hi) {
            area = (hi - lo) * min(height[lo], height[hi]);
            max_area = max(max_area, area);

            if (height[lo] < height[hi])
                lo++;
            else
                hi--;
        }

        return max_area;
        
    }
};