class Solution {
public:

    int solve(int i, vector<int>&arr, int k, vector<vector<int>>dp){
        if(k == 0)
        return 0;

        if(i == 0){
            if(k % arr[i] == 0){
                return k / arr[i];
            }
            return 1e9;
        }

        if(dp[i][k] != -1)
        return dp[i][k];

        int notPick = solve(i-1, arr, k, dp);
        int pick = INT_MAX;
        if(arr[i] <= k){
            pick = 1 + solve(i, arr, k - arr[i], dp);
        }

        return dp[i][k] = min(pick , notPick);

    }

    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(target+1, 0));
        
        for(int j=0;j<=target;j++){
            if(j % coins[0] == 0){
                dp[0][j] = j / coins[0];
            }
            else
            dp[0][j] = 1e9;
        }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=target;j++){
                int notPick = dp[i-1][j];
                int pick = INT_MAX;
                if(coins[i] <= j){
                    pick = 1 + dp[i][j - coins[i]];
                }
                
                dp[i][j] = min(pick , notPick);
            }
        }

        int ans = dp[n-1][target];
        if(ans >= 1e9) return -1;
        return ans;
    }
};