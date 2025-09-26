class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);

            else{  // s[i] is closing bracket

                if(!st.empty()){ // and stack is not empty
                    char ch = st.top();

                    if(s[i] == ')' && ch == '(')
                    st.pop();
                    else if(s[i] == '}' && ch == '{')
                    st.pop();
                    else if(s[i] == ']' && ch == '[')
                    st.pop();
                    else
                    return false;
                }
                else // s[i] is closing bracket & stack is empty
                return false;
            }
        }

        return st.size() == 0 ? true : false;
    }
};