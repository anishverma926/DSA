class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxWater = 0;
        int i = 0;
        int j = n-1;

        while(i <= j){
            int h = min(height[j], height[i]);
            int w = j - i;

            int waterArea = h * w;

            if(height[j] <= height[i]){
                j--;
            }
            else{
                i++;
            }

            maxWater = max(maxWater, waterArea);
        }

        return maxWater;

    }
};