//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1151093861/
//Time: O(n m)
//Space: O(1)

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if (m == 0) return 0;
    for (int i = 0; i <= n - m; i++) {
        if (haystack[i] == needle[0] && haystack.substr(i, m) == needle)
            return i;
    }
    return -1;
}