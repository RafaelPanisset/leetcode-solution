//https://leetcode.com/problems/sort-characters-by-frequency/
//Time: O(n long n)
//Space: O(n)
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }
        vector<pair<int, char> > arrCharacters;
        for (auto it : mp) {
            arrCharacters.push_back({it.second, it.first});
        }
        sort(arrCharacters.rbegin(), arrCharacters.rend());
        string ans = "";
        for (auto it : arrCharacters) {
            for (int i = 0; i < it.first; i++) {
                ans += it.second;
            }
        }
        return ans;
    }
};