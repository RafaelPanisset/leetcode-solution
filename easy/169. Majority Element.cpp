//https://leetcode.com/problems/majority-element/
//Time: O(n)
//Space: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        int ans = 0, occu =  0;
        for (auto it : mp) {
            if (it.second > occu) {
                occu = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};