class Solution {
public:
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        int n = s.size();
        
        if(i == n || j == n)
        return 0;

        if(dp[i][j] != -1)
        return dp[i][j];
        
        int not_match = max(solve(i + 1, j, s, t, dp), solve(i, j + 1, s, t, dp));

        int match = 0;
        if(s[i] == t[j]){
            match = 1 + solve(i + 1, j + 1, s, t, dp);
        }
        

        return dp[i][j] = max(match, not_match);
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;

        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n, vector<int> (n, -1));

        return solve(0, 0, s, t, dp);
    }
};