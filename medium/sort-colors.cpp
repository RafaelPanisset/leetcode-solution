
//https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                i++;
                left++;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
            }
        }  
    }
};  