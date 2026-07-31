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

    int maxdia=0;

    int calheight(TreeNode* root)
    {
        if(root == NULL)    return 0;

        int leftheight = calheight(root->left);
        int rightheight = calheight(root->right);

        maxdia = max(maxdia, leftheight+rightheight);

        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        maxdia=0;
        calheight(root);
        return maxdia;
        
    }
};