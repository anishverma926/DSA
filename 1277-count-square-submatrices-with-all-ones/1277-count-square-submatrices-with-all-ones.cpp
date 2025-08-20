class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i == m || j == n)
        return 0;

        if(grid[i][j] == 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int right = solve(i, j + 1, grid, dp);
        int diagonal = solve(i + 1, j + 1, grid, dp);
        int left = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + min({right, diagonal, left});
    }

    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1)
                ans += solve(i, j, matrix, dp);

            }
        }

        return ans;
    }
};