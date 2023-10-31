//https://leetcode.com/problems/longest-substring-without-repeating-characters/   

//T: O(n)
//S: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        int count[128] = {0};
        for (int left = 0, right = 0; right < s.size(); right) {
            count[s[right]]++;
            if (cont[s[right]] > 1) {
                cont[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

