class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(nums[0] != nums[1])
        return nums[0];

        if(nums[n-1] != nums[n-2])
        return nums[n-1];

        for(int i = 0; i < n; i++){
            if(i > 0 && (i + 1 < n) &&  nums[i] != nums[i+1] 
                && nums[i] != nums[i-1])
            return nums[i];
        }

        return -1;
    }
};