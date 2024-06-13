//https://leetcode.com/problems/encode-and-decode-strings/description/
//Time: o(n)
//Space: O(L), where L is the total length of all decoded strings 
class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string encodedString = "";
        for (int i = 0; i < n; i++) {
            string sizeString = to_string(strs[i].size());
            encodedString += sizeString + "." + strs[i];
        }
        return encodedString;

    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> decodedStrings;
        int left = 0;
        while (left < n) {
            int right = left;
            while (right < n && s[right] != '.')
                right++;
            int sizeString = stoi(s.substr(left, right - left));
            decodedStrings.push_back(s.substr(right + 1, sizeString));

            left = right + 1 + sizeString;
        }
            
        return decodedStrings;
    }
};
