class Solution {
public:
    int calculateOp(int a, int b, string c) {
        if (c == "+") return a + b;
        if (c == "-") return a - b;
        if (c == "/") return a / b;
        if (c == "*") return a * b;
        return 0;
    }

    int eval(vector<string>& tokens) {
        stack<int> st;

        for(const string& t : tokens) {
            if(t == "+" || t == "-" || t == "*" || t == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(calculateOp(a, b, t));
            } else {
                st.push(stoi(t)); 
            }
        }
        return st.top(); 
    }

    int priority(char c) {
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }

    int calculate(string s) {
        int i = 0;
        stack<char> st;
        vector<string> postfix; 

        while(i < s.size()) {
            if(s[i] == ' ') {
                i++;
                continue;
            }

            if(isdigit(s[i])) {
                string num = "";
                while(i < s.size() && isdigit(s[i])) {
                    num += s[i];
                    i++;
                }
                postfix.push_back(num);
            }
            else if(s[i] == '(') {
                st.push(s[i]);
                i++;
            }
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
                i++; 
            }
            else {
                while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                    postfix.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
                i++; 
            }
        }
        
        while(!st.empty()) {
            postfix.push_back(string(1, st.top()));
            st.pop();
        }   
        
        return eval(postfix);
    }
};