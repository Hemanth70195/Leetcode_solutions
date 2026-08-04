class Solution {
public:

    struct cmp
    {
        bool operator()(const pair<string,int> &a , const pair<string,int> &b)
        {
            if(a.second == b.second)    return a.first<b.first;
            return a.second > b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string,int> mp;

        for(string &word : words)  
            mp[word]++;

        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q;

        for(auto &it : mp)
        {
            q.push(it);
            if(q.size() > k)
                q.pop();
        }

        vector<string> ans;

        while(!q.empty())
        {
            ans.push_back(q.top().first);
            q.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};