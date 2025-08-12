class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int i, int n, vector<int>& arr, vector<vector<int>> & dp){
        if(n == 0)
        return 1;

        if(i == arr.size())
        return 0;

        if(dp[i][n] != -1)
        return dp[i][n];

        int not_take = solve(i+1, n, arr, dp);
        int take = 0;

        if(arr[i] <= n){
            take = solve(i+1, n - arr[i], arr, dp);
        }

        return dp[i][n] = (take + not_take) % mod;
    }
    int numberOfWays(int n, int x) {
        vector<int> arr;

        for(int i = 1; i <= n; i++){
            int val = pow(i, x);
            if(val <= n)
            arr.push_back(val);
            else
            break;
        }

        int m = arr.size();

        vector<vector<int>> dp(m, vector<int> (n + 1, -1));

        return solve(0, n, arr, dp);
    }
};