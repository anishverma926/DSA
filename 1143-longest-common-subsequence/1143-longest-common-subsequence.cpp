class Solution {
public:
    // we got the tle because of we did not declare as a reference
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == 0 || j == 0)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        int not_match = max(solve(i-1, j, s1, s2, dp), solve(i, j-1, s1, s2, dp));

        int match = 0;
        if(s1[i - 1] == s2[j - 1]){
            match = 1 + solve(i - 1, j - 1, s1, s2, dp);
        }

        return dp[i][j] = max(match, not_match);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));

        return solve(m, n, text1, text2, dp);
    }
};