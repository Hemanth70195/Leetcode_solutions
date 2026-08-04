class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> present(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());

        for(int i=mini;i<maxi;i++)
        {
            if(present.find(i) == present.end() )   ans.push_back(i);
        }
        return ans;
    }
};