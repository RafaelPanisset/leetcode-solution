//https://leetcode.com/problems/number-of-islands/description/
//Time: o(n m)
//Space: o(n m)
class Solution {
public:
    bool isValid (int row, int column, vector<vector<char>>& grid, int n, int m) {
        return row >= 0 && row < n && column >= 0 && column < m && grid[row][column] == '1';
    }
    void getIsland(int row, int column, vector<vector<char>>& grid) {
        grid[row][column] = '0';
        if (isValid(row - 1, column, grid, grid.size(), grid[0].size()))
            getIsland(row - 1, column, grid);
        
        if (isValid(row + 1, column, grid, grid.size(), grid[0].size()))
            getIsland(row + 1, column, grid);
       
        if (isValid(row, column - 1, grid, grid.size(), grid[0].size()))
            getIsland(row, column - 1, grid);
        
        if (isValid(row, column + 1, grid, grid.size(), grid[0].size()))
            getIsland(row, column + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {   
                if (isValid(i, j, grid, n, m)) {
                    getIsland(i, j, grid);
                    answer++;
                }
            }
        }
        return answer;
    }
};
