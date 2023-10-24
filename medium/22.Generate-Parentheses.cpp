class Solution {
    vector<string> ans;
public:
   void dfs(int n1, int n2, string &s) {
        if (!n1 && !n2) {
            ans.push_back(s);
            return;
        }
        if (n1 > 0) {
            s += '(';
            dfs(n1 - 1, n2, s);
            s.pop_back();
        }
        if (n2 > n1) {
            s += ')';
            dfs(n1, n2 - 1, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(n, n, s);
        return ans;
    }
};