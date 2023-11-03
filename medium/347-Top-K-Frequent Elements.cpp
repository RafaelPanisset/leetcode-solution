//https://leetcode.com/problems/top-k-frequent-elements/n
//Time: o(N + M)
//Space: o(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
        unordered_map<int, int> mp;
        for (auto &element : nums) {
            mp[element]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &[element, ocurr] : mp) {
            bucket[ocurr].push_back(element);
        }
        vector<int> ans;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (auto &element : bucket[i]) {
                if (k)
                    ans.push_back(element);
                else
                    return ans;
                k--;
            }
        }
        return ans;
    }
};