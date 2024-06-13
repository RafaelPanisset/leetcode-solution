//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/1267869599/
//Time:  o(log n)
//Space: o(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid + 1 < n && nums[mid] > nums[mid + 1])
                return nums[mid + 1];

            if (mid && nums[mid] < nums[mid - 1])
                return nums[mid];

            if (nums[left] < nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return nums[0];
    }
};
