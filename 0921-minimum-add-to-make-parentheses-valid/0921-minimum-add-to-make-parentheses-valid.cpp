class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        
        int count = 0;
        
        for(int i = 0; i < n; i++){
            char ch = s[i];
            
            // opening brackets
            if(ch == '(')
            count++;
            
            // closing brackets
            else{
                if(count && ch == ')'){
                    count--;
                }
                else 
                count++;
            }
        }

        return count;
    }
};