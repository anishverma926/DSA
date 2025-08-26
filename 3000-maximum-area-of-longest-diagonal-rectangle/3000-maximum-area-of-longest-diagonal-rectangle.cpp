class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();

        int longDiagonal = 0;
        int maxArea = 0;

        for(int i = 0; i < n; i++){
            int length = dimensions[i][0];
            int width = dimensions[i][1];

            // we were using int for decimal values
            int diagonal = length * length + width * width;
            
            if(diagonal >= longDiagonal){
                maxArea = length * width; 
                longDiagonal = diagonal;
            }
            else if(diagonal == longDiagonal)
            maxArea = max(maxArea, length * width);
        }

        return maxArea;
    }
};