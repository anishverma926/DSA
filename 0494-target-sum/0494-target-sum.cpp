class Solution {
public:
    int solve(int i, vector<int>& nums, int target){
        int n = nums.size();

        if(i == n){
            if(target == 0)
            return 1;
            else
            return 0;
        }

        int add = solve(i+1, nums, target - nums[i]);
        int subtract = solve(i+1, nums, target + nums[i]);

        return add + subtract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        return solve(0, nums,target);
    }
};