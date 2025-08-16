class Solution {
public:
    int maximum69Number (int num) {
        vector<int> nums;

        while(num > 0){ 
            nums.push_back(num % 10);
            num /= 10;
        }

        reverse(nums.begin(), nums.end()); 

        int n = nums.size();

        for(int i = 0; i < n; i++){ // O(n)
            if(nums[i] == 6){
                nums[i] = 9;
                break;
            }
        }

        int ans = 0;

        for(int num : nums){ // O(n)
            ans = ans * 10 + num;
        }

        return ans;
    }
};