class Solution {
public:
    int ans = INT_MIN;
    
    int dfs(TreeNode* root){
        if (!root) return 0;
        auto left = max(0,  dfs(root->left));
        auto right = max(0,  dfs(root->right));
        int sum = right + left +root->val;
        ans = max(sum, ans);
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
        
};