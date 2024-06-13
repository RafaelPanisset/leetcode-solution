//https://leetcode.com/problems/minimum-window-substring/description/
//Time: o(n + m)
//Space: o(1)
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> mpS, mpT;
        for (auto& it : t)
            mpT[it]++; 

        int have = 0, need = mpT.size();
        int start = -1, leng = INT_MAX;
        for (int left = 0, right = 0; right < n; right++) {
            if (mpT.count(s[right])) {
                mpS[s[right]]++;
                if (mpS[s[right]] == mpT[s[right]])
                    have++;
                
                while (have == need) {
                    if (right - left + 1 < leng) {
                        leng = right - left + 1;
                        start = left;
                    }
                    if (mpT.count(s[left])) {
                        mpS[s[left]]--;
                        if (mpS[s[left]] < mpT[s[left]]) 
                            have--;  
                    }
                    left++;
                }
            }
        } 
        return leng == INT_MAX ? "" : s.substr(start, leng);           
    }
};
