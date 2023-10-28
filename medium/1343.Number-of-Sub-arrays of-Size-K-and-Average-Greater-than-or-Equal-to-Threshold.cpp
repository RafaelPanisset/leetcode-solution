//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/



class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        
        int window = 0;
        for (int i = 0; i < k; i++)
            window += arr[i];
        
        int ans = (window / k) >= threshold;
        for (int i = k; i < n; i++) {
            window += (arr[i] - arr[i - k]);
            ans += (window / k) >= threshold;
        }
        return ans;
    }
};