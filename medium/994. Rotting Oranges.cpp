//https://leetcode.com/problems/rotting-oranges/description/
//Time:  o(n m)
//Space: o(n m)
class Solution {
public:
    //up, down, left, right
    vector<int> dX = {-1, 1, 0, 0};
    vector<int> dY = {0, 0, -1, 1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> rottenOranges;
        int freshOranges = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freshOranges++;
                }
                else if (grid[i][j] == 2) {
                    rottenOranges.push({i, j});
                }
            }
        }
        int minutesTakenSoFar = 0;
        while (!rottenOranges.empty() && freshOranges) {
            int sizeOfQueue = rottenOranges.size();
            for (int i = 0; i < sizeOfQueue; i++) {
                pair<int, int> currentOrange = rottenOranges.front();
                rottenOranges.pop();
                for (int k = 0; k < 4; k++) {
                    int newRow = currentOrange.first + dX[k];
                    int newColumn = currentOrange.second + dY[k];
                    if (newRow >= 0 && newRow < n && newColumn >= 0 && newColumn < m && grid[newRow][newColumn] == 1) {
                        grid[newRow][newColumn] = 2;
                        rottenOranges.push({newRow, newColumn});
                        freshOranges--;
                    }
                }
            }
            minutesTakenSoFar++;
        }
        return freshOranges == 0 ? minutesTakenSoFar : -1;
    }
};
