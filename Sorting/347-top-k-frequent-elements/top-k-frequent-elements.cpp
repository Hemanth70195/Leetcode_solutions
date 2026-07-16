class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> heap;
        for (auto& entry : map) {
            heap.push({entry.second,entry.first});
            if(heap.size()>k)
            {
                heap.pop();
            }
        }
        while(!heap.empty())
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};