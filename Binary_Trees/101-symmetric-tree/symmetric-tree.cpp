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
    bool isSymmetric(TreeNode* root) 
    {
        if( root == NULL)   return true;

        return ismirror(root->left , root->right);
    }
    
    private:
    bool ismirror(TreeNode* leftnode,TreeNode* rightnode)
    {
        if(leftnode == nullptr && rightnode== nullptr)
        {
            return true;
        }
        if(leftnode == nullptr || rightnode== nullptr)
        {
            return false;
        }

        return (leftnode->val == rightnode->val) && ismirror(leftnode->left,rightnode->right) && ismirror(leftnode->right,rightnode->left);
    }
};