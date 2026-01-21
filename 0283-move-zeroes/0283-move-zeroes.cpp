class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
        return;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        int x = temp.size();
        for(int i=0;i<x;i++){
            nums[i] = temp[i];
        }

        for(int i = x; i < n; i++){
            nums[i] = 0;
        }
    }
};