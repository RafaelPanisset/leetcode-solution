//https://leetcode.com/problems/sign-of-the-product-of-an-array/
//Timme: o(n)
//Space: O(1)
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cntNegative = 0, n = int(nums.size());
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                return 0;
            if (nums[i] < 0)
                cntNegative++;
        }
        if (cntNegative % 2)
            return -1;
        else 
            return 1;
    }
};