class Solution {
public:
    string removeDuplicates(string s) {
        string s1="";
        stack <char> t;
        for(char c : s)
        {
            if(t.empty())
                t.push(c);
            else if(t.top() == c)
            {
                t.pop();
            }
            else
                t.push(c);

        }
        while(!t.empty())
        {
            s1+=t.top();
            t.pop();
        }
        reverse(s1.begin(),s1.end());
        return s1;
    }
};