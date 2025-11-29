class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        leftMax[0] = 0;

        for(int i = 1; i < n; i++){
            leftMax[i] = max(height[i-1], leftMax[i-1]);
        }

        vector<int> rightMax(n);
        rightMax[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(height[i+1], rightMax[i+1]);
        }

        int countWater = 0;
        for(int i = 0; i < n; i++){
            int minHeight = min(leftMax[i], rightMax[i]);

            if(minHeight > height[i])
            countWater += minHeight - height[i];
        }

        return countWater;
    }
};