class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0)
        return 1;

        // long long N = n;
        
        if(n < 0){
            x = 1 / x;
            n = -n;
        }

        double half = myPow(x, n / 2);
        double ans = (half * half);

        if(n % 2 == 1){
            ans = (ans * x);
        }

        return n > 0 ? ans : 1 / ans;
    }
};