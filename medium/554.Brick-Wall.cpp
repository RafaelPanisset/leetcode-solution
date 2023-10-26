//https://leetcode.com/problems/brick-wall/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> gapMap;
        for (auto& it : wall) {
            int pfx = 0;
            for (int i = 0; i < int(it.size()) - 1; i++) {
                pfx += it[i];
                gapMap[pfx]++;
            }
        }

        int mostGap = 0;
        for (auto& it : gapMap)
            mostGap = max(mostGap, it.second);
      
        return int(wall.size()) - mostGap;
    }
};



