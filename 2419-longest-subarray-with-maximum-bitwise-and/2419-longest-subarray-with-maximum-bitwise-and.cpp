class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        for(int num : nums){
            maxi = max(maxi, num);
        }

        int len = 0;
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            if(maxi == nums[i]){
                len++;
                maxLen = max(maxLen, len);
            }    
            else{
                len = 0;
            }

        }

        return maxLen;
    }
};