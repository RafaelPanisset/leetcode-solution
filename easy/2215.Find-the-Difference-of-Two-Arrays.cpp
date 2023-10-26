//https://leetcode.com/problems/find-the-difference-of-two-arrays/



class Solution {
public:
    vector<int> getValues(vector<int>& num, unordered_map<int, int>& cnt) {
        set<int> ans;
        for (int i = 0; i < num.size(); i++)
            if (!cnt.count(num[i]))
                ans.insert(num[i]);
        return vector(ans.begin(), ans.end());
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;

        for (auto& it : nums1)
            cnt1[it]++;
        for (auto& it : nums2)
            cnt2[it]++;
        
        vector<int> ans1 = getValues(nums1, cnt2);
        vector<int> ans2 = getValues(nums2, cnt1);

        return {ans1, ans2};  
    }
};