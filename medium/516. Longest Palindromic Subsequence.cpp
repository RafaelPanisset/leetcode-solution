//https://leetcode.com/problems/longest-palindromic-subsequence
//Time: O(n²)
//Space: O(n²)

class Solution {
public:
    int dp[1001][1001];
    int vis[1001][1001];
    int solve(string &s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (vis[i][j]) {
            return dp[i][j];
        }
        vis[i][j] = true;
        if (s[i] == s[j]) {
            dp[i][j] = 2 + solve(s, i+1, j-1);
            return dp[i][j];
        }
        int best = max(solve(s, i+1, j), solve(s, i, j-1));
        dp[i][j] = best;
        return best;
    }
    int longestPalindromeSubseq(string s) {
        memset(vis, 0, sizeof(vis));
        return solve(s, 0, s.size()-1);
    }
};
