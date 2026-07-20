class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end());
        int remove=0;
        if(intervals.empty())
        {
            return 0;
        }
        int prevend=intervals[0][1];
        for(int i=1; i<intervals.size(); i++)
        {
            int curst=intervals[i][0];
            int curend=intervals[i][1];
            if(prevend <= curst)
            {
                prevend=curend;
            }
            else
            {
                remove++;
                prevend=min(prevend,curend);
            }
        }
      return remove;  
    }
};