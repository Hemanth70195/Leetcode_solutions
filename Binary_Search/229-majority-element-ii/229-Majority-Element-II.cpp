class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        vector<int> result;
        for(int i : nums)
            count[i]++;

        for(auto it : count)
        {
            int key = it.first;
            int value = it.second;

            if(value > nums.size()/3)
            {
                result.push_back(key);
            }
        }
        return result;
    }
};