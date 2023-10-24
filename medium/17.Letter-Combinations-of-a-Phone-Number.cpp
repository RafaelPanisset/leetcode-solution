class Solution {
    vector<string> values{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> ans;
public:
    void dfs(int start, string &dg, string &s) {
        if (start == dg.size()) {
            ans.push_back(s);
            return;
        }
        for (auto it : values[dg[start] - '2']) {
            s += it;
            dfs(start + 1, dg, s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = int(digits.size());
        if (!n)
            return {};
        string s;
        dfs(0, digits, s);
        return ans;
    }
};