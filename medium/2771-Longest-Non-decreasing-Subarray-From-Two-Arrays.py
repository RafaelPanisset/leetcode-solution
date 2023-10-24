#https://leetcode.com/contest/weekly-contest-353/problems/longest-non-decreasing-subarray-from-two-arrays/ 
class Solution(object):
    def maxNonDecreasingLength(self, nums1, nums2):
        n = len(nums1)
        dp1 = [1] * n  
        dp2 = [1] * n
        
        for i in range(1, n):
            if nums1[i] >= nums1[i-1]:
                dp1[i] = max(dp1[i], dp1[i-1] + 1)  # Update dp1[i] to the maximum of its current value and dp1[i-1] + 1, if nums1[i] is greater than or equal to nums1[i-1].
            if nums1[i] >= nums2[i-1]:
                dp1[i] = max(dp1[i], dp2[i-1] + 1)  # Update dp1[i] to the maximum of its current value and dp2[i-1] + 1, if nums1[i] is greater than or equal to nums2[i-1].
            if nums2[i] >= nums2[i-1]:
                dp2[i] = dp2[i-1] + 1  # Update dp2[i] to dp2[i-1] + 1, if nums2[i] is greater than or equal to nums2[i-1].
            if nums2[i] >= nums1[i-1]:
                dp2[i] = max(dp2[i], dp1[i-1] + 1)  # Update dp2[i] to the maximum of its current value and dp1[i-1] + 1, if nums2[i] is greater than or equal to nums1[i-1].
        
        return max(max(dp1), max(dp2)) 
