//https://leetcode.com/problems/binary-tree-preorder-traversal/
//Time: O(N) | Space: O(N)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* ptr = root;
        vector<int> ans;

        while (ptr != nullptr || !stk.empty()) {
            while (ptr != nullptr) {
                ans.push_back(ptr->val);
                stk.push(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            ptr = ptr->right;
        }
        return ans;
    }
};