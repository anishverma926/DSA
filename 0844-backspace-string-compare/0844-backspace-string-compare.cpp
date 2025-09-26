class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        stack<int> st1, st2;

        for(char ch : s){
            if(!st1.empty() && ch == '#')
            st1.pop();
            else if(ch != '#')
            st1.push(ch);
        }

        for(char ch : t){
            if(!st2.empty() && ch == '#')
            st2.pop();
            else if(ch != '#')
            st2.push(ch);
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top() != st2.top())
            return false;

            st1.pop();
            st2.pop();
        }

        return st1.empty() && st2.empty();  // miskake done 
    }
};