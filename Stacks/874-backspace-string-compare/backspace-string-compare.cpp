class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack <char> t1;
        stack <char> t2;
        // string s1="",s2="";
        for(char c : s)
        {
            if(t1.empty())
            {
                if(c=='#')  continue;
                t1.push(c);
            }
            else if(c== '#')
                t1.pop();
            
            else
                t1.push(c);
        }
        for(char c : t)
        {
            if(t2.empty())
            {
                if(c=='#')  continue;
                t2.push(c);
            }
            else if(c== '#')
                t2.pop();
            
            else
                t2.push(c);
        }
        while(!t1.empty() && !t2.empty())
        {
            if(t1.top() != t2.top())
                return false;
            t1.pop();
            t2.pop();
        }
        if(t1.empty() && t2.empty())
            return true;
        
        else
            return false;
        return true;
    }
};