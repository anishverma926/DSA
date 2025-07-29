class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans;
        if(n == 1){
            return nums[0];
        }

        if (nums[0] != nums[1]) {
            return nums[0]; // unique element is first
        }

        if (nums[n-1] != nums[n-2]) {
            return nums[n-1]; // unique element is last
        }
        for(int i=1;i<n-1;i++){
            if(nums[i] != nums[i+1] && nums[i-1] != nums[i]){
                ans = nums[i];
            }
        }

        return ans;
    }
};