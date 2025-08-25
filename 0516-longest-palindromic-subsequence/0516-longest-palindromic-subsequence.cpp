class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;

        reverse(t.begin(), t.end());
        int ans = 0;

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        for(int i = 0; i <= n; i++)
        dp[i][0] = 0;
        
        for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int not_match = max(dp[i - 1][j], dp[i][j - 1]);

                int match = 0;
                if(s[i-1] == t[j-1]){
                    match = 1 + dp[i - 1][j - 1];
                }
                
                dp[i][j] = max(match, not_match);
            }
        }

        return dp[n][n];
    }
};