https://leetcode.com/problems/stone-game-vi/

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<pair<int, int> > sum(n);
        for (int i = 0; i < n; i++) {
            sum[i] = {a[i] + b[i], i};
        }
        sort(sum.rbegin(), sum.rend());
        int aliceScore = 0, bobScore = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                aliceScore += a[sum[i].second];
            }
            else {
                bobScore += b[sum[i].second];
            }
        }
        return aliceScore > bobScore ? 1 : aliceScore < bobScore ? -1 : 0;
    }
};




