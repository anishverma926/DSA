class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0)
        return true;

        if(i < 0)
        return false;

        if(dp[i][target] != -1)
        return dp[i][target];

        int not_take = solve(i-1, nums, target, dp);
        int take = 0;
        if(nums[i] <= target){
            take = solve(i-1, nums, target - nums[i], dp);
        }

        return dp[i][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int num : nums)
        totalSum += num;

        if(totalSum % 2)
        return false;

        int target = totalSum / 2;

        vector<vector<int>> dp(n+1, vector<int> (target + 1, -1));

        return solve(n-1, nums, target, dp);
    }
};