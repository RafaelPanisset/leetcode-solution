
//https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mS, mT;
        for (auto& it : s)
            mS[it]++;
        for (auto& it: t)
            mT[it]++;
        
        bool answer = true;
        for (int i = 0; i < 26; i++) {
            int j = 'a' + i;
            if (mS[j] != mT[j])
                return false;
        }
        return answer;
    }
};