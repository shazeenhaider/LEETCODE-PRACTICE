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
    bool hasOne(TreeNode* root) {
    if (root == NULL) 
    return false;
    if (root->val == 1) 
    return true;
    return hasOne(root->left) || hasOne(root->right);
}

    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) 
        return NULL;

        // prune left subtree
        if (!hasOne(root->left)) {
            root->left = NULL;
        } 
        // prune right subtree
        if (!hasOne(root->right)) {
            root->right = NULL;
        } 
         pruneTree(root->left);
         pruneTree(root->right);
        // finally check current node
        if (root->val == 0 && root->left == NULL && root->right == NULL) {
            return NULL;
        }

        return root;
    }
};
