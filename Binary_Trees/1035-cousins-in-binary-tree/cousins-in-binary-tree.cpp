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

    TreeNode* px=nullptr;
    TreeNode* py=nullptr;
    int dx=-1;
    int dy=-1;

    void dfs(TreeNode* root,TreeNode* parent,int depth,int x,int y)
    {
        if(root == NULL)    return;

        if(root->val == x)
        {
            px=parent;
            dx=depth;
        }

        if(root->val == y)
        {
            py=parent;
            dy=depth;
        }
        dfs(root->left,root,depth+1,x,y);
        dfs(root->right,root,depth+1,x,y);
        return;
    }

    bool isCousins(TreeNode* root, int x, int y) 
    {
        dfs(root,nullptr,0,x,y);
        return px!=py && dx == dy;  
    }
};