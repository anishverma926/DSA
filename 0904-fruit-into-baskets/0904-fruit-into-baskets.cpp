class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int maxLen = 0;

        int i = 0;
        int j = 0;

        unordered_map<int, int> mp;

        while(j < n){
            mp[fruits[j]]++;

            if(mp.size() <= 2){
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
            while(mp.size() > 2){
                mp.erase(fruits[i]);
                i++;
            }
            
        }

        return maxLen;
    }
};