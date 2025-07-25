class Solution {
public:
    int reverse(int x) {
        long long ans = 0;

        while(x != 0){
            int temp = x % 10;
            ans = ans * 10 + temp;
            x /= 10;
        }

        if(ans < INT_MIN || ans > INT_MAX)
        return 0;

        return ans;
    }
};