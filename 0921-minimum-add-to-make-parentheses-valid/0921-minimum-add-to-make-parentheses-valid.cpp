class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        stack<char> st;
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            // opening brackets
            if(ch == '(')
            st.push(ch);
            
            // closing brackets
            else{
                if(!st.empty() && ch == ')' && st.top() == '('){
                    st.pop();
                }
                else 
                st.push(ch);
            }
        }

        return st.size();
    }
};