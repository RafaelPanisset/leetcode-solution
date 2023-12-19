//https://leetcode.com/problems/pascals-triangle/
//Time: o(n²)
//Space: o(n²)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > triangles;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = triangles[i - 1][j - 1] + triangles[i - 1][j];
            }
            triangles.push_back(row);
        }
        return triangles;
    }
};