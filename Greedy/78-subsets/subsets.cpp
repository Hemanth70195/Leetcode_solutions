class Solution {
public:

    vector<int> cur;
    vector<vector<int>> ans;

    void dfs(int idx,vector<int> nums)
    {
        if(idx == nums.size())
        {
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        dfs(idx+1,nums);
        cur.pop_back();
        dfs(idx+1,nums);

    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        dfs(0,nums);
        return ans;
        
    }
};