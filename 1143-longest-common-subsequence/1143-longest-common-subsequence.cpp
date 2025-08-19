class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for(int i = 0; i <= m; i++)
        curr[0] = 0;

        for(int j = 0; j <= n; j++)
        prev[j] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int not_match = max(prev[j], curr[j-1]);

                int match = 0;
                if(text1[i - 1] == text2[j - 1]){
                    match = 1 + prev[j - 1];
                }

                curr[j] = max(match, not_match);
            }
            prev = curr;
        }

        return prev[n];
    }
};