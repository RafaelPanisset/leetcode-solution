//https://leetcode.com/problems/longest-consecutive-sequence/
//Time: O(n)
//Space: O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestSequence = 0;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int currentSequence = 0, j = 0;
                while (numSet.count(num + j)) {
                    currentSequence++;
                    j++;
                }
                longestSequence = max(longestSequence, currentSequence);
            }
        }
        return longestSequence;
    }
};
