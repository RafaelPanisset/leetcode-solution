//https://leetcode.com/problems/longest-palindromic-subsequence-after-at-most-k-operations
//Time: O(n² k)
//Space: O(n² k)

class Solution {
public:
    int dp[201][201][201];
    int vis[201][201][201];
    int solve(const string &s, int i, int j, int k) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (vis[i][j][k])
            return dp[i][j][k];
        vis[i][j][k] = true;
        
        int best = max(solve(s, i+1, j, k), solve(s, i, j-1, k));

        int diff = abs(s[i]-s[j]);
        int cost = min(diff, 26-diff);
        if (cost <= k) {
            best = max(best, 2 + solve(s, i+1, j-1, k - cost));
        }
        dp[i][j][k] = best;
        return best;
    }
    int longestPalindromicSubsequence(string s, int k) {
        memset(vis, 0, sizeof(vis));
        return solve(s, 0, s.size()-1, k);
    }
};
