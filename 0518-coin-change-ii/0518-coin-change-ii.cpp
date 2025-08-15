class Solution {
public:
    int solve(int i, vector<int>& coins, int amount){
        if(amount == 0)
        return 1;

        if(i == 0){
            if(amount % coins[0] == 0)
            return 1;
            else
            return 0;
        }

        int not_take = solve(i - 1, coins, amount);

        int take = 0;
        if(coins[i] <= amount){
            take = solve(i, coins, amount - coins[i]);
        }

        return take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        return solve(n-1, coins, amount);
    }
};