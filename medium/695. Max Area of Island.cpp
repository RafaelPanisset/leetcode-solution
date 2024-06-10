//https://leetcode.com/problems/max-area-of-island/description/
//Time: o(n)
//Space: o(1)
class Solution {
public:
    bool valided (int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1);
    }
    void dfs (int i, int j, vector<vector<int>>& grid, int& size) {
        size++;
        grid[i][j] = 0;
        if (valided(i - 1, j, grid))
            dfs(i - 1, j, grid, size);
        if (valided(i + 1, j, grid))
            dfs(i + 1, j, grid, size);
        if (valided(i, j - 1, grid))
            dfs(i, j - 1, grid, size);
        if(valided(i, j + 1, grid))
            dfs(i, j + 1, grid, size);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && grid[i][j] == 1) {
                    int size = 0;
                    dfs(i, j, grid, size);
                    maxArea = max(maxArea, size);
                }
            }
        }
        return maxArea;
    }
};
