class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) 
    {
        vector<vector<int>> res;
        if(firstList.empty() || secondList.empty())
        {
            return res;
        }
        int i=0,j=0;
        while(i < firstList.size() && j < secondList.size())
        {
            int f1=firstList[i][0],f2=firstList[i][1];
            int s1=secondList[j][0],s2=secondList[j][1];
            int start=max(f1,s1),last=min(f2,s2);
            if(start<= last )
            {
                res.push_back({start,last});
            }
            if(f2 < s2 )
                i++;
            else    j++;
        }
        return res;
    }
};