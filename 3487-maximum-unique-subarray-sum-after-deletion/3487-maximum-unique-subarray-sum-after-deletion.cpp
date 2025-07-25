class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int left = 0, maxSum = nums[0], currSum = 0;  // Initialize maxSum properly
        
        for (int i = 0; i < n; i++) {
            while (st.count(nums[i])) {
                st.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }
            st.insert(nums[i]);
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};