class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin(), potions.end()); // O(m log m)

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            long long minPotion = (success + spells[i] - 1) / spells[i]; // ceiling division

            int s = 0;
            int e = m - 1;
            int firstValid = m;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(potions[mid] >= minPotion) {
                    firstValid = mid;
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }

            ans[i] = m - firstValid;
        }

        return ans;
    }
};
