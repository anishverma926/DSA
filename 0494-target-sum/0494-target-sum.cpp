class Solution {
public: 
int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == 0) {
        if (target == 0 && arr[0] == 0)
        return 2; // Include or exclude the zero
        if (target == 0 || target == arr[0])
        return 1;

        return 0;
    }
    
    if (dp[i][target] != -1)
    return dp[i][target];
    
    int notPick = solve(i - 1, target, arr, dp);
    int pick = 0;
    if (arr[i] <= target) {
        pick = solve(i - 1, target - arr[i], arr, dp);
    }
    
    return dp[i][target] = (pick + notPick);
}
  
int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solve(n - 1, k, arr, dp);
}

    int findTargetSumWays(vector<int>& arr, int target) {
        int totalSum = 0;
        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
        }
    
        if (totalSum < target || (totalSum - target) % 2 != 0)
        return 0;
    
        int sum = (totalSum - target) / 2;
        return findWays(arr, sum);

    }
};