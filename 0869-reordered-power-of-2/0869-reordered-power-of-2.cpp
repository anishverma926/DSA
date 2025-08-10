class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> st;

        if(st.empty()){
            for(int p = 0; p <= 29; p++){
                string s = to_string(1 << p);
                st.insert(s);
            } 
        }

        string str = to_string(n);
        sort(str.begin(), str.end());

        return st.count(str);
    }
};