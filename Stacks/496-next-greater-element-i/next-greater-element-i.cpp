class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        for(int i = 0;i<nums1.size();i++)
        {
            int cur = nums1[i];
            bool foundin2=false;
            int ngreat = -1;
            for(int j=0;j<nums2.size();j++)
            {
                if(nums1[i] == nums2[j])
                    foundin2=true;

                if(foundin2 && nums2[j] > cur)
                {
                    ngreat=nums2[j];
                    break;
                }
                
            }
            result.push_back(ngreat);
        }
        return result;
        
    }
};