//https://leetcode.com/problems/search-insert-position/
//Time: O(log n)
//Space: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;

            }
            else {
                right = mid - 1;

            }
        }
        return right + 1;
    }
};