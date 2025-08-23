class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        set<vector<int>> set;  // for storing the all answer elements

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                unordered_set<long long> st;  // for checking the 4th element
                for(int k = j + 1; k < n; k++){
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];

                    long long fourth = target - sum;
                    
                    if(st.count(fourth)){
                        vector<int>temp = {nums[i], nums[j], nums[k], (int)fourth};
                        sort(temp.begin(), temp.end());
                        set.insert(temp);
                    }

                    st.insert(nums[k]);
                }
            }
        }

        vector<vector<int>> ans(set.begin(), set.end());

        return ans;
    }
};