class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
        return 0;

        sort(nums.begin(), nums.end());

        int ans = 1;
        int lastSmaller = nums[0]; // so we can compare consecutive element

        int count = 1;

        for(int i = 0; i < n; i++){
            
            // 1 1 2 2 2 3 4 100 200, o/p = 4
            if(nums[i] == lastSmaller)
            continue;

            if(nums[i] == lastSmaller + 1){
                count++;
            }
            else{
                count = 1;
            }

            lastSmaller = nums[i];
            ans = max(ans, count);
            
        }

        return ans;
    }
};