class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            int count = 0;
            unordered_map<char, int> mp;
            for(int j = i; j < n; j++){
                if(mp[s[j]] == 0){
                    count++;
                    ans = max(ans, count);
                    mp[s[j]]++;
                }
                else 
                break;

            }
        }

        return ans;
    }
};