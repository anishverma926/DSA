class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }

        int missingValue = 1;
        
        for(int i = 1; i <= n; i++){
            if(!mp.count(i)){
                missingValue = i;
                break;
            }
        }

        return missingValue;
    }
};