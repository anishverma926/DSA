class Solution {
public:
    int solve(int i, int n, int x, vector<vector<int>>& dp){
        if(n == 0)
        return 1;

        int val = pow(i, x); // 1^2, 2^2, 3^2, 4^2
        if(val > n) // 16 > n
        return 0;

        if(dp[i][n] != -1)
        return dp[i][n];

        int not_take = solve(i+1, n, x, dp);
        int take = 0;

        if(val <= n){
            take = solve(i+1, n - val, x, dp);
        }

        return dp[i][n] = take + not_take;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return solve(1, n, x, dp);
    }
};