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
    //Best approach till seen 
    int result = 0;
    int helper(TreeNode* node)
    {
        if(node == NULL) return 0;
       int leftPath = helper(node->left);
       int rightPath = helper(node->right);
        // root is included
       result = max(result, leftPath + rightPath);

       return 1 + max(leftPath, rightPath);
    }

    int diameterOfBinaryTree(TreeNode* root) {
       if(root == NULL) return 0;
        helper(root);
       return result;
    }
};