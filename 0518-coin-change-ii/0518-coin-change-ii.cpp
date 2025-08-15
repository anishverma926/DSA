class Solution {
public:
    long solve(int i, vector<int>& arr, int k, vector<vector<int>>& dp){
        if (i == 0){  
            return (k % arr[0] == 0);
        }

        if(dp[i][k] != -1)
        return dp[i][k];

        long notPick = 0 + solve(i-1, arr, k, dp);
        long pick = 0;
        if(arr[i] <= k){
            pick = solve(i, arr, k-arr[i], dp);
        }

        return dp[i][k] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));

        for(int T=0;T<=amount;T++){
            dp[0][T] = (T % coins[0] == 0);
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                long notPick = dp[i-1][j];
                long pick = 0;
                if(coins[i] <= j){
                    pick = dp[i][j-coins[i]];
                }
                dp[i][j] = pick + notPick;

            }
        }
        return dp[n-1][amount];
    }
};
