class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int lo = 0, hi = n - 1;
        //get the first position of the target value
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] <  target)
                lo = mid + 1;
            else
                hi = mid - 1;
        } 
        if (lo >= n || nums[lo] != target) return {-1, -1};
        int left = lo;
        lo = 0, hi = n - 1;
        //get the last position of the target value
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return {left, hi};
    }
};