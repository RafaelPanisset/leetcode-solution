//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& a) {
        ios_base::sync_with_stdio(false); std::cin.tie(NULL);
        int ans = 0, n = a.size(), d = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) {
                ans += a[i] - a[i - 1];
            }
        }
        return ans;   
    }
};