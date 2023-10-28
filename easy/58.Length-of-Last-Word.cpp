//https://leetcode.com/problems/length-of-last-word/description
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;

        for (int i = s.size(); i >= 0; i--) {
            if (isalpha(s[i])) {
                while (i >= 0 && isalpha(s[i])) {
                    ans++;
                    i--;
                }
                break;
            }
        }
        return ans;
    }
};