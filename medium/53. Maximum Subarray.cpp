//https://leetcode.com/problems/maximum-subarray/description/
//Time: o(n)
//Space: o(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxElementSoFar = nums[0];
        int maxSubArraySum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxElementSoFar = max(nums[i], maxElementSoFar + nums[i]);

            if (maxElementSoFar > maxSubArraySum) {
                maxSubArraySum = max(maxSubArraySum, maxElementSoFar);
            }
        }
        return maxSubArraySum;
    }
};
