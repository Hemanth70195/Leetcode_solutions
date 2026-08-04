class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue<pair<int,int>> maxheap;
        
        for(int i=0;i<n;i++)
        {
            int distsq=(points[i][0]*points[i][0])+(points[i][1]*points[i][1]); 
            maxheap.push({distsq,i});
            if(maxheap.size()>k)
            {
                maxheap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxheap.empty())
        {
            int poi=maxheap.top().second;
            result.push_back(points[poi]);
            maxheap.pop();
        }

        return result;
        
    }
};