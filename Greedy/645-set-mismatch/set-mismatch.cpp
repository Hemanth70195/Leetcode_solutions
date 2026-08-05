class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        vector<int> ans(2);
        vector<int> mp(nums.size()+1,0);
        for(int i : nums)
            mp[i]++;

        for(int i=0;i<mp.size();i++)
        {
            if(mp[i] == 2)  ans[0]=i;
            if(mp[i] == 0)  ans[1]=i;
        }
        return ans;
        
    }
};