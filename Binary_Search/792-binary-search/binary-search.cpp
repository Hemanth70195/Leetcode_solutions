class Solution {
public:
    int search(vector<int>& nums, int target) {
        int middle,left,right;
        right=nums.size()-1;
        left=0;
        middle=(left+right)/2;
        while(left<=right)
        {
            middle=(left+right)/2;
            if(target==nums[middle])
            {
                return middle;
            }
            else if(target<nums[middle])
            {
                right=middle-1;
            }
            else
            {
                left=middle+1;
            }
        }
        return -1;
    }
};