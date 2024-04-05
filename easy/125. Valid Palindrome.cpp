//https://leetcode.com/problems/valid-palindrome/description/
//Time: O(n)
//Space:O(m)
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string t;
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                if (isalpha(s[i])) {
                    t += tolower(s[i]);
                }
                else {
                    t += s[i];
                }
            }
        }
        int m = t.size();
        for (int i = 0; i < m / 2; i++)
            if (t[i] != t[m - i - 1])
                return false;
        return true;
    }
};