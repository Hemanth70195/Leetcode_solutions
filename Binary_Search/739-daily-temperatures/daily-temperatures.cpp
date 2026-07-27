class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
     {
        // int n=temperatures.size();
        // vector<int> res(n,0);
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(temperatures[j] > temperatures[i])
    //             {
    //                 res[i]=j-i;
    //                 break;
    //             }
    //         }
    //     }

    //   return res; 
    int n=temperatures.size();
    vector<int> res(n,0);
    stack<int> st;

    for(int i=0;i<n;i++)
    {
        while(!st.empty() && temperatures[i] > temperatures[st.top()])
        {
            int prev=st.top();
            st.pop();
            res[prev]=i-prev;
        }
        st.push(i);
    }
    return res;
    
     
    }
};