class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> fq(101);
        for (auto it : nums) {
            fq[it]++;
        }
        
        int mx = 0;
        for (int i = 0; i < fq.size(); i++)
            mx = max(mx, fq[i]);
        
        int ans = 0;
        for (int i = 0; i < fq.size(); i++)
            ans += (fq[i] == mx);
        
        return ans  * mx;
    }
};