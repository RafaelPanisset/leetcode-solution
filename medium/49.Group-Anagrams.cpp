//https://leetcode.com/problems/group-anagrams/description/
//Time: o(NMlogM)
//Space: o(NM)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < n; i++) {
            string t = s[i];
            sort(t.begin(), t.end());
            mp[t].push_back(s[i]);
        }
        vector<vector<string>> ans(mp.size());
        int k = 0;
        for (auto [stg, values] : mp) {
            for (int i = 0; i < values.size(); i++) {
                ans[k].push_back(values[i]);
            }
            k++;
        }
        return ans;
    }
};

