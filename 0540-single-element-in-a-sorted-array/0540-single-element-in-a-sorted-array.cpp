class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        while(i < n-1){
            if(nums[i] == nums[i+1])
            i += 2;
            else
            return nums[i];
        }

        return nums[n-1];
    }
};