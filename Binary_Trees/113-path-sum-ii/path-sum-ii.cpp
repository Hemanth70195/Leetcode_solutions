/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int k, vector<int>& cur,vector<vector<int>>& result) {
        if (root == NULL)
            return;

        cur.push_back(root->val);

        if (root->left == NULL && root->right == NULL && k == root->val)
            result.push_back(cur);

        else {
            dfs(root->left, k - root->val, cur, result);
            dfs(root->right, k - root->val, cur, result);
        }
        cur.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> result;
        dfs(root, targetSum, cur, result);
        return result;
    }
};