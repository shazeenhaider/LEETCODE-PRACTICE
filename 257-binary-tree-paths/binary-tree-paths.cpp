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
    vector<string> answer;

    void dfs(TreeNode* root, string& path) {
        if (root == NULL) return;

        int len = path.length();  // save state

        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        if (root->left == NULL && root->right == NULL) {
            answer.push_back(path);
        } else {
            dfs(root->left, path);
            dfs(root->right, path);
        }

        path.resize(len);  // resizing path to track another 
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        string path = "";
        dfs(root, path);
        return answer;
    }
};
