//https://leetcode.com/problems/contains-duplicate/description/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = false;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] == nums[i - 1])
                return true;
        return answer;
    }
};
