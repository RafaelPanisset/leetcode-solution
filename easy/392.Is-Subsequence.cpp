//https://leetcode.com/problems/is-subsequence/
//Time: O(n)
//Space:O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = int(t.size()), m = int(s.size());
        int j = 0;
        if (m == 0)
            return true;
        for (int i = 0; i < n; i++) {
            if (t[i] == s[j]) {
                j++;
                if (j == m)
                    return true;
            }
        }
        return false;
    }
};