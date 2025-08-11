class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sumArr = 0;
        for(int i = 0; i < n; i++){
            sumArr += nums[i];
        }

        int requireSum = n * (n + 1) / 2;

        int missingEle = requireSum - sumArr;

        return missingEle;
    }
};