//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//Time: O(n)
//Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        int i = 0, j = 1;
        for (int j = 1; j < n; j++) {
            if (a[i] < a[j]) {
                mx = max(mx, a[j] - a[i]);
            }
            else {
                i = j;
            }
        }
        return mx;
    }
};