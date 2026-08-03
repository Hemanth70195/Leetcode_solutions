class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int n = g.size();
        int m = s.size();

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int child=0;
        int cookies=0;

        while(child<n && cookies<m)
        {
            if(s[cookies] >= g[child])
                child++;
            cookies++;
        }

        return child;
        
    }
};