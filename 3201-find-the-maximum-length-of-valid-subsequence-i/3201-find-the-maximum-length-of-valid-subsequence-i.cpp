class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evenCount = 0;
        int oddCount = 0;

        for(int num : nums){
            if(num % 2 == 0){
                evenCount++;
            }
            else{
                oddCount++;
            }
        }

        int parity = nums[0] % 2;
        int len = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] % 2 != parity){
                len++;
                parity = nums[i] % 2;
            }
        }

        return max({len, evenCount, oddCount});
    }
};