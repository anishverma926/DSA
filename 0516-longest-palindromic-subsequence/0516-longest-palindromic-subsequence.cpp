class Solution {
public:
    int solve(int i, int j, string& s, string& t, int& ans, vector<vector<int>>& dp){
        if(i < 0 || j < 0)
        return 0;

        int count = 0;
        int match = 0;

        if(dp[i][j] != -1)
        return dp[i][j];

        if(s[i] == t[j]){
            count = 1 + solve(i - 1, j - 1, s, t, ans, dp);
            ans = max(ans, count);
        }
        else{
            count = max(solve(i - 1, j, s, t, ans, dp), solve(i, j - 1, s, t, ans, dp));;
        }

        return dp[i][j] = count;
    }

    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;

        reverse(t.begin(), t.end());

        int ans = 0;

        vector<vector<int>> dp(n, vector<int> (n, -1));

        solve(n - 1, n - 1, s, t, ans, dp);

        return ans;
    }
};