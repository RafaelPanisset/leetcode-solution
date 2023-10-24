class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++) {
            if (i && a[i] == a[i - 1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && a[j] == a[j - 1]) continue;
                long long toFind = (long long)target -  (long long)a[i] -  (long long)a[j];
                int left = j + 1, right = n - 1;
                while (left < right) {
                    int sum = a[left] + a[right];
                    if (sum == toFind) {
                        ans.push_back({a[i], a[j], a[left++], a[right--]});
                        while (left < right && a[right] == a[right + 1]) right--;
                        while (left < right && a[left] == a[left - 1]) left++;
                    }
                    else if ((long long)sum > toFind) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
            }
        }
        return ans;
    }
};