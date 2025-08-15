class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for(int i = 0; i < n; i++){
            dp[i][0] = 1;
        }

        for(int t = 0; t <= amount; t++){
            if(t % coins[n-1] == 0)
            dp[n-1][t] =  1;
            else
            dp[n-1][t] = 0;
        }

        for(int i = n-2; i >= 0; i--){
            for(int t = 0; t <= amount; t++){
                long long not_take = dp[i + 1][t];

                long long take = 0;
                if(coins[i] <= t){
                    take = dp[i][t - coins[i]];
                }

                dp[i][t] = (take + not_take);
            }
        }

        return dp[0][amount];
    }
};