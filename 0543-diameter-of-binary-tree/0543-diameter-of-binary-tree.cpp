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
    int solve(TreeNode* root, int& ans)
    {
        if(!root) return -1;

        int l = 1 + solve(root->left, ans);
        int r = 1 + solve(root->right, ans);
        
        int toreturn = 0;
        
        toreturn = max({toreturn, l, r});
        ans = max({ans, l + r, toreturn});
        return toreturn;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};