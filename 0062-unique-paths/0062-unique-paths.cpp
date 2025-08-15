class Solution {
public:
    int countPath(int a, int b, vector<vector<int>>&dp){
        if(a == 0 && b == 0)
        return 1;
        
        if(a < 0 || b < 0)
        return 0;
         
        if(dp[a][b] != -1)
        return dp[a][b];
        
        int up = countPath(a-1, b, dp);
        int left = countPath(a, b-1, dp);
        
        return dp[a][b] = up + left;
    }

    int uniquePaths(int a, int b) {
        vector<vector<int>>dp(a, vector<int>(b,-1));
        return countPath(a-1, b-1, dp);
    }
};