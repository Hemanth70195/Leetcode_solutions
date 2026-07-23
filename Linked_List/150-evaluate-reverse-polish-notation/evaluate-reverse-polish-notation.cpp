class Solution {
public:

    int calculate(int a,int b,char c)
    {
        switch(c)
        {
            case '+':
                return a+b;

            case '-':
                return a-b;
            
            case '/':
                return a/b;

            case '*':
                return a*b;

            default: return 0;
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack <int> st;

        for(const string& c : tokens)
        {
           
            if(c == "+" || c == "-" || c== "*" || c == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int res=calculate(a,b,c[0]);
                st.push(res);
            }

            else
            {
               st.push(stoi(c));
            }
        }
        return st.top(); 
    }
};