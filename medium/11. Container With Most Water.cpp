//https://leetcode.com/problems/container-with-most-water/description/
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();
        int left = 0, right = n - 1, ans = 0;
        while (left < right) {
            int area = (right - left) * min(a[left], a[right]);
            ans = max(ans, area);
            if (a[left] >= a[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return ans;
    }
};