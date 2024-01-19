//https://leetcode.com/problems/word-pattern/description/
//Time: O(n + m)
//Space: O(n + m)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> mp1;
        unordered_map<string, int> mp2;

        string ans1 = "", ans2 = "";
        int value1 = 0, value2 = 0;
        for (auto it : pattern) {
            if (mp1.find(it) == mp1.end()) {
                mp1[it] = value1++;
            }
            ans1 += to_string(mp1[it]);
        }
        string t = "";
        for (int i = 0; i < s.size(); i++) {
            if (!isalpha(s[i])) {
                if (mp2.find(t) == mp2.end()) {
                    mp2[t] = value2++;
                }
                ans2 += to_string(mp2[t]);
                t = "";
            }
            else {
                t += s[i];
            }
        }
        if (!t.empty()) {
            if (mp2.find(t) == mp2.end()) {
                    mp2[t] = value2++;
            }
            ans2 += to_string(mp2[t]);
        }
        return ans1 == ans2;
    }
};