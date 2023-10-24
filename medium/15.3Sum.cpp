class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int> > ans;
        int n = a.size();
        for (int i = 0; i < n - 2; ++i) {
            if (i && a[i] == a[i - 1]) continue;
            int lo = i + 1, hi = n - 1;
            while (lo < hi) {
                int sum = a[i] + a[lo] + a[hi];
                if (sum == 0) ans.push_back({a[i], a[lo], a[hi]});
                if (sum >= 0) {
                    hi--;
                    while (lo < hi && a[hi] == a[hi + 1]) hi--;
                }
                if (sum < 0) {
                    lo++;
                    while (lo < hi && a[lo] == a[lo - 1]) lo++;
                }
            }
        }
        return ans;
    }
};