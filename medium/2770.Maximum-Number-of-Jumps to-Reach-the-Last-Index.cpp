//https://leetcode.com/contest/weekly-contest-353/problems/maximum-number-of-jumps-to-reach-the-last-index/
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), -1);
        
        // Set the maximum number of jumps to reach the first index as 0
        dp[0] = 0;

        for (int i = 1; i < nums.size(); i++) {
            // Iterate through the previous indices
            for (int j = 0; j < i; j++) {
                // Check if the difference between the current element and the previous element satisfies the condition
                if (-target <= nums[i] - nums[j] && nums[i] - nums[j] <= target) {
                    // Check if the maximum number of jumps for the previous index is not -1 (indicating it is reachable)
                    if (dp[j] != -1) {
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[nums.size() - 1];
    }
};
