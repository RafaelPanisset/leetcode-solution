//https://leetcode.com/problems/single-number/description/
//Time: o(n)
//Space: o(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer =  nums[0];
        for (int i = 1; i < nums.size(); i++)
            answer ^= nums[i];
        return answer;
    }
};
