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

    void dfs(TreeNode* root,string cur,vector<string>& ans)
    {
        if(root == NULL)    return;

        cur+=to_string(root->val);
        if(root->left == NULL && root->right == NULL ) 
            ans.push_back(cur);

        cur+="->";

        dfs(root->left,cur,ans);
        dfs(root->right,cur,ans);
        cur.pop_back();

    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> ans;
        string cur;

        dfs(root,cur,ans);
        return ans;
        
    }
};