//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int getMax(TreeNode* node, int& maxValue) {
        if (node == nullptr)
            return 0;
        
        int leftPath = getMax(node->left, maxValue);
        int rightPath = getMax(node->right, maxValue);

        maxValue = max({
            maxValue,
            leftPath + node->val,
            rightPath + node->val,
            leftPath + rightPath + node->val,
            node->val
        });

        return max(0, node->val + max(leftPath, rightPath));
    }
    int maxPathSum(TreeNode* root) {
        int maxValue = INT_MIN;
        getMax(root, maxValue);
        return maxValue;
    }
};
