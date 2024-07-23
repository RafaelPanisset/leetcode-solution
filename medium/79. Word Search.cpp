//https://leetcode.com/problems/word-search/description/
//Time:  o(n * m 4^L)
//Space: o(n * m + L)
class Solution {
public:
    bool dfs(vector<vector<bool>>& visit, const vector<vector<char>>& board, int i, int j, int indexWord, const string& word) {
        if (indexWord == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visit[i][j] || board[i][j] != word[indexWord]) {
            return false;
        }
        visit[i][j] = true;
        bool found  = dfs(visit, board, i - 1, j, indexWord + 1, word) ||
        dfs(visit, board, i + 1, j, indexWord + 1, word) ||
        dfs(visit, board, i, j - 1, indexWord + 1, word) ||
        dfs(visit, board, i, j + 1, indexWord + 1, word);
        visit[i][j] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(visit, board, i, j, 0, word))
                        return true;
                }
            }
        }
        return false;
    }
};
