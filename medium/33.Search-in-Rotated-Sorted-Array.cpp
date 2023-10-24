class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size();
        int lo = 0, hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (a[mid] == target)
                return a[mid];

            if (a[mid] > target) {
                if (a[mid] > a[right])
                else
            }
            else {
                if (a[mid] > a[left])
                else
            }
        }
        return -1;
    }
};