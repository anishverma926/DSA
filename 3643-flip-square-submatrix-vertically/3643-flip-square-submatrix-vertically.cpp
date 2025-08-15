class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int i = x;  // i = 0;
        int j = x + k - 1; // j = 1

        while(i <= j){ // O(k * k)
            for(int col = y; col < y + k; col++){  // col = 2, 3
                swap(grid[i][col], grid[j][col]);  // swap(4, 2) , (2, 3)
            }

            i++;
            j--;
        }

        return grid;
    }
};