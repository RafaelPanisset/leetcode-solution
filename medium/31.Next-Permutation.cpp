class Solution {
public:
    void nextPermutation(vector<int>& a) {
        std::next_permutation(a.begin(), a.end());
    }
};