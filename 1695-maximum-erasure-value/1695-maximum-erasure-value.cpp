class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        unordered_set<int> st;

        int i = 0;
        int sum = 0;

        for(int j = 0; j < n; j++){
            while(st.find(nums[j]) != st.end()){ 
                st.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            st.insert(nums[j]);
            sum += nums[j];
            
            maxSum = max(maxSum, sum);
            
        }

        return maxSum;
    }
};