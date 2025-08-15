class Solution {
public:
    int solve(int i, vector<int>& coins, int amount, vector<vector<int>>& dp){
        int n = coins.size();

        if(i == n-1){
            if(amount % coins[i] == 0)
            return amount / coins[i];
            else
            return 1e9;
        }

        if(dp[i][amount] != -1)
        return dp[i][amount];

        int not_take = solve(i + 1, coins, amount, dp);

        int take = INT_MAX; // because we have to find minimum coins
        if(coins[i] <= amount){
            take = 1 + solve(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount] = min(take, not_take);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount + 1, -1));
        int ans = solve(0, coins, amount, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};