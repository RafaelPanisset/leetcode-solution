//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
//Time: o(n)
//Space: o(n)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
        int n = arr.size();
        vector<int> ans(n);
        ans[n - 1] = -1;
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i + 1], arr[i + 1]);
        }
        return ans;
    }
};


