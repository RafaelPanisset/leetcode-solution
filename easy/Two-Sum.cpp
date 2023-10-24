class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);

        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end() && it->second != i) {
                int key = it->first;
                int value = it->second;

                if (it->second != i) {
                    ans = {i, it->second};
                    return ans;
                }
            }
        }
        return ans;
    }
};