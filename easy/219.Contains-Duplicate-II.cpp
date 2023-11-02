//https://leetcode.com/problems/contains-duplicate-ii/
//Time: O(n log n)
//Space: O(n) 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int> > values;
        for (int i = 0; i < nums.size(); i++) {
            values.push_back({nums[i], i});
        }
        sort(values.begin(), values.end());

        for (int i = 1; i < values.size(); i++) {
            if (values[i].first == values[i - 1].first) {
                if (abs(values[i].second - values[i - 1].second) <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};



//Time: O(n)
//Space: O(n) 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && (i - mp[nums[i]] <= k))
                return true;
            mp[nums[i]] = i;
        }   
        return false;
    }
};

