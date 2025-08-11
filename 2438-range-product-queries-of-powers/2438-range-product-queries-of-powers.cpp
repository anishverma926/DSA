class Solution {
public:
    long long mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;

        int i = 0;
        while(n){
            if(n & 1)
            powers.push_back(pow(2, i));

            n = n >> 1;
            i++;
        }

        int m = queries.size();
        vector<int> ans(m);

        for(int i = 0; i < m; i++){
            int left = queries[i][0];
            int right = queries[i][1];

            long long product = 1;

            for(int j = left; j <= right; j++){
                product = (product * powers[j]) % mod;
            }

            ans[i] = (int)product;
        }

        return ans;
    }
};