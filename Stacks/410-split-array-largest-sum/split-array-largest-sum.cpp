class Solution {
public:

    bool isvalid(vector<int>& nums,int n,int k,int maxall)
    {
        int stu=1,pages=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] > maxall)    return false;

            if(pages+nums[i] <= maxall )    pages+=nums[i];

            else
            {
                stu++;
                pages=nums[i];
            }
        }
        if(stu > k) return false;
        else    return true;
    }



    int splitArray(vector<int>& nums, int k) 
    {
        int st =0, sum=0, ans=-1;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            st=max(st,nums[i]);
        }
        int end=sum;
        while(st<=end)
        {
            int mid = st+(end-st)/2;
            if(isvalid(nums,nums.size(),k,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                st=mid+1;
            }

        }
        return ans;
    }
};