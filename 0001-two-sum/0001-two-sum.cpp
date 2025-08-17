class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 1;
        map<int, int>mp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int more = target - nums[i];
            if(mp.find(more) != mp.end()){
                return {mp[more], i};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }
};