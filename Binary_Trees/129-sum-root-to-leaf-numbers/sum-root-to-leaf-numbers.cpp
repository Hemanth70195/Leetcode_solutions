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

    void dfs(TreeNode* root, vector<int> cur,int& ans)
    {
        if(root == NULL)    return;

        cur.push_back(root->val);
        if(root->left == NULL && root->right == NULL)   
        {
            vector<int> temp=cur;
            int a=0;
            for(int i=0;i<temp.size();i++)
            {
                a=(a*10)+temp[i];
            }
            ans+=a;
        }

        dfs(root->left,cur,ans);
        dfs(root->right,cur,ans);
        cur.pop_back();
    }

    int sumNumbers(TreeNode* root) 
    {
        int ans=0;
        vector<int> cur;
        dfs(root,cur,ans);
        return ans;
        
    }
};