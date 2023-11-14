// https://leetcode.com/problems/baseball-game
//Time: o(n)
//Space: o(n)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> tmp;
        for (auto it : operations) {
            if (it == "+") {
                int n = tmp.size();
                tmp.push_back(tmp[n - 1] + tmp[n - 2]);
            }
            else if (it == "D") {
                int n = tmp.size();
                tmp.push_back(tmp[n - 1] * 2);
            }
            else if (it == "C") {
                tmp.pop_back();
            }
            else {
                tmp.push_back(stoi(it));
            }
            
        }
        int ans = 0;
        for (int i = 0; i < tmp.size(); i++)
            ans += tmp[i];
        return ans;
        
    }
};