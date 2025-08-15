class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        for(int target = 0; target <= amount; target++){
            if(target % coins[n-1] == 0)
            prev[target] = target / coins[n-1];
            else
            prev[target] = 1e9;
        }

        for(int i = n-2; i >= 0; i--){
            for(int target = 0; target <= amount; target++){
                int not_take = prev[target];

                int take = INT_MAX; // because we have to find minimum coins
                if(coins[i] <= target){
                    take = 1 + curr[target - coins[i]];
                }

                curr[target] = min(take, not_take);
            }
            
            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};