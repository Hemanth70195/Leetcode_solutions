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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> res;
        if(root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelsize=q.size();
            vector<int> cur;

            for(int i=0;i<levelsize;++i)
            {
                TreeNode* node = q.front();
                q.pop();

                cur.push_back(node->val);
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};