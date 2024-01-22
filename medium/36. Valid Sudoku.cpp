//https://leetcode.com/problems/valid-sudoku/description/
//Time: o(n n)
//Space: o(n n)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int, char>, int> row, column;
        int n = board.size(), m = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.')  continue;
                row[{i, board[i][j]}]++;
                column[{j, board[i][j]}]++;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[{i, board[i][j]}] > 1 )
                    return false;
                if (column[{j, board[i][j]}] > 1)
                    return false;
            }
        } 
        for (int startRow = 0; startRow < n; startRow += 3) {
            for (int endColumn = 0; endColumn < m; endColumn += 3) {
                set<char> st;
                for (int i = startRow; i < startRow + 3; i++) {
                    for (int j = endColumn; j < endColumn + 3; j++) {
                        if (board[i][j] == '.') continue;
                        if (!st.count(board[i][j]))
                            st.insert(board[i][j]);
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
};