//https://leetcode.com/problems/find-special-substring-of-length-k/description/
//Time: o(n k)
//Space: o(1)
class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.size();
        for (int i = 0; i <= n - k; i++) {
            string t = s.substr(i, k);
            bool ok = true;
            for (int j = 1; j < k; j++) 
                if (t[j] != t[0])
                    ok = false;

            if (!ok) {
                continue;
            }
            if (i > 0 && s[i - 1] == t[0]) {
                continue;
            }
            if (i + k < n && s[i + k] == t[0]) {
                continue;
            }
            return true;
        }
        return false;
    }
};
