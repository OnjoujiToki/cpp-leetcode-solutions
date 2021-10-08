class Solution {
public:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder,int p, int q, int len) {
        if (len == 0) return NULL;
        int rootVal = preorder[p];
        int index = q;
        while(inorder[index] != rootVal) index++;
        index -= q;
        TreeNode* T = new TreeNode(rootVal);
        T->left = dfs(preorder, inorder, p+1, q, index);
        T ->right = dfs(preorder, inorder,p+index+1,q+ index+1, len- index-1);
        return T;                                                                                                                                                
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder, 0, 0, inorder.size());
    }
};