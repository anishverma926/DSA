class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_set<char>st;

        int maxLen = 0;
        while(j < n)
        {
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            }

            else{
                st.erase(s[i]);
                i++;
            }
        }
        
        return maxLen;

    }
};