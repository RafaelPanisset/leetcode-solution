//https://leetcode.com/problems/trapping-rain-water/description/
//Time: o(n)
//Space: o(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
            left[i] = max(height[i], left[i - 1]);

        right[n - 1] = height[n - 1];
        for (int i = n - 2;  i >= 0; i--)
            right[i] = max(height[i], right[i + 1]);

        int trappingWater = 0;
        for (int i = 1; i < n - 1; i++) {
            int heightToTheLeft = left[i - 1];
            int heightToTheRight = right[i + 1];
            int minHeight = min(heightToTheLeft, heightToTheRight);

            trappingWater += max(0, minHeight - height[i]);
        }         
        return trappingWater;
    }
};
