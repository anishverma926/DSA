class Solution {
public:
    int solve(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0)
        return true;
        
        if(i == 0)
        return (arr[0] == target);
        
        if(dp[i][target] != -1)
        return dp[i][target];
        
        bool notTake = solve(i-1, target, arr, dp);
        bool take = false;
        if(target >= arr[i]){
            take = solve(i-1, target - arr[i], arr, dp);
        }
        
        return dp[i][target] = take || (notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum +=  nums[i];
        }

        if(totalSum % 2) 
        return false;

        int target = totalSum / 2;

        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(n-1, target, nums, dp);

    }
};