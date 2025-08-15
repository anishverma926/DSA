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
        vector<vector<int>>dp(a, vector<int>(b,0));
        
        dp[0][0] = 1;
        
        if(a < 0 || b < 0)
        return 0;
        
        for(int i=0;i<a;i++){
            dp[i][0] = 1;
        }
        
        for(int j=0;j<b;j++){
            dp[0][j] = 1;
        }
        
        for(int i=1;i<a;i++){
            for(int j=1;j<b;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[a-1][b-1];
    }
};