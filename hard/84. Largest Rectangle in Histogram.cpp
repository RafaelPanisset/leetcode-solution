//Time: o(n)
//Space: o(o)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stack;
        int n = heights.size();
        int maxRectangle = 0;
        for (int i = 0; i < n; i++) {
            int startIndex = i;
            while (int(stack.size()) && stack.back().first > heights[i]) {
                auto histogram = stack.back();
                startIndex = histogram.second;
                stack.pop_back();
                maxRectangle = max(maxRectangle, histogram.first *  (i - histogram.second));
            }
            stack.push_back({heights[i], startIndex});
        }
        for (auto &it : stack) {
            maxRectangle = max(maxRectangle, it.first * (n - it.second));
        }
        return maxRectangle;
    }
};
