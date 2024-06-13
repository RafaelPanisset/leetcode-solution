//https://leetcode.com/problems/subtree-of-another-tree/description/
//Time: o(n m)  n is the number of nodes in the root and m is the number of nodes in the subroot.
//Space: o(max(hN, hM))

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
    bool isSame(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr)
            return true;
        if (node1 == nullptr || node2 == nullptr)
            return false;
        if (node1->val != node2->val)
            return false;
        

        return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);

        bool left = isSame(node1->left, node2->left);
        bool right = isSame(node1->right, node2->right);

        if (left == false || right == false)
            return false;
        return true;
    }
    void check(TreeNode* root, TreeNode* subRoot, bool& ok) {
        if (root == nullptr)
            return;
        
        if (isSame(root, subRoot))
            ok = true;
        
        check(root->left, subRoot, ok);
        check(root->right, subRoot, ok);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ok = false;
        check(root, subRoot, ok);
        return ok;
    }
};
