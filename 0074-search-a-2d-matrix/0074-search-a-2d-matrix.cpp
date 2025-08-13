class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0, e = n*m-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            int row_i = mid / m, col_i = mid % m;
            if(matrix[row_i][col_i] == target){
                return true;
            }
            else if(matrix[row_i][col_i] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return false;
    }
};