class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN,cursum=0;
        for(int i : nums)
        {
            cursum+=i;
            maxsum=max(cursum,maxsum);
            if(cursum<0)
            {
                cursum=0;
            }
        }
        return maxsum;
        
    }
};