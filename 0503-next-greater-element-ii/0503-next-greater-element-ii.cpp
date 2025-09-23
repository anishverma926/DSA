class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>s;
        
        for(int i=0;i<(2*n-1);i++){
            while(!s.empty() && nums[i%n] > nums[s.top()%n]){
                ans[s.top()%n] = nums[i%n];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};