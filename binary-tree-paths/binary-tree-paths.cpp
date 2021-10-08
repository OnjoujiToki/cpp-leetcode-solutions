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
    vector<string> res;
    void dfs(TreeNode* root,string path) {
        if (!root) return;
        path = path + to_string(root->val) + "->";
        if (!root->left && !root->right) {
            path.pop_back();
            path.pop_back();
            res.push_back(path);
        }
        if (root->left) {
            dfs(root->left,path);
        }
        if (root->right) {
            dfs(root->right,path);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return res;
        string path;
        dfs(root,path);
        return res;
    }
};