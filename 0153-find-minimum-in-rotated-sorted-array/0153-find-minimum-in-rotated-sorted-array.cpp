class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int s = 0, e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]){
                s = mid + 1;
            }
            else{
                ans = nums[mid];
                e = mid - 1;
            }
        }
        return ans;
    }
};