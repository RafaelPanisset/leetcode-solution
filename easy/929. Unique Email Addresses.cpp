//https://leetcode.com/problems/unique-email-addresses/
//Time: o(n m)
//Space: o(n m)

class Solution {
public:
 
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string, int> mp;
        for (auto it : emails) {
            bool foundAt = false;
            string s = "";
            for (int i = 0; i < it.size();) {
                if (it[i] == '.' && !foundAt) {
                    i++;
                }
                else if (it[i] == '+' && !foundAt) {
                    while (it[i] != '@') {
                        i++;
                    }
                    s += it[i++];
                    foundAt = true;
                }
                else if (it[i] == '@' && !foundAt) {
                    s += it[i++];
                    foundAt = true;
                }
                else {
                    s += it[i++];
                }
            }
            mp[s]++;
        }
        int ans = 0;
        for (auto it : mp)
            ans += it.second >= 1;
        return ans;
    }
};