class Solution {
public:

    bool ispossible(vector<int>& nums,int mid,int m)
    {
        int mag=1,lastpos=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if( (nums[i] - lastpos) >= mid)
            {
                mag++;
                lastpos=nums[i];
            }
            if(mag == m)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& nums, int m) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int st=1;
        int ans=0;
        int end=nums.back()-nums.front();
        
        while(st<=end)
        {
            int mid = st+(end-st)/2;
            if(ispossible(nums,mid,m))
            {
                ans=mid;
                st=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
    }
};