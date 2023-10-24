class Solution {
public:
    string multiply(string a, string b) {
        std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
        int n = a.size(), m = b.size();
        vector<int> res(n + m);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i + j] += (a[i] - '0') * (b[j] - '0');
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;    
            }
        }
        while (res.size() > 1 && res.back() == 0)
            res.pop_back();
        
        string ans;
        for (int i = 0; i < res.size(); i++)
            ans += res[i] + '0';
        reverse(ans.begin(), ans.end());
        return ans;
}

};





