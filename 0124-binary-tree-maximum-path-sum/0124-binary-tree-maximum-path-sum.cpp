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
        if(!root) return 0;

       int l = solve(root->left, ans);
       int r = solve(root->right, ans);
       
       l = max(l, 0);
       r = max(r, 0);

        // if both are negative then l=0, r=0..by above line and Yes ! The root value is taken.This Is Your Correction

        ans = max(ans, root->val + l + r);
        
        int ret = root->val + max(l, r);
        ans = max(ans, ret);
        return ret;
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};