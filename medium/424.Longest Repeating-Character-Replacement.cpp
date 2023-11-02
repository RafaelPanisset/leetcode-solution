//https://leetcode.com/problems/longest-repeating-character-replacement/
//Time: o(n)
//Space: o(1)
class Solution {
public:
    int findValue(int cnt[26]) {
        int sum = 0;
        for (int i = 0; i < 26; i++)
            sum = max(sum, cnt[i]);
        return sum;
    }
    int characterReplacement(string s, int k) {
        int cnt[26] = {0};
        int n = s.size();
        
        int ans = 0;
        for (int i = 0, j = 0; j < n; j++) {
            cnt[s[j] - 'A']++;
            int value = findValue(cnt);
            if ((j - i + 1) - value <= k) {
                ans = max(ans, j - i + 1);
            }
            else {
                while (true) {
                    cnt[s[i++] - 'A']--;
                    value = findValue(cnt);
                    if ((j - i + 1) - value <= k) {
                        break;
                    }
                }
            }
        }
        return ans;
    }
};




 