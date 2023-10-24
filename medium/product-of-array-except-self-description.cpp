
//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n);
        ans[0] = 1;
        ans[n - 1] = 1;
        int prefix = 1;
        for (int i  = 1; i < n; i++) {
            ans[i] = prefix * a[i - 1];
            prefix *= a[i - 1];
        }
        int suffix = 1;
        for (int i = n - 2; i >= 0; i--) {
            ans[i] *= suffix * a[i + 1];
            suffix *= a[i + 1];
        }
        return ans;
    }
};
