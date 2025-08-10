class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n <= 0)
        return false;

        if(n == 1)
        return true;

        return (n % 2 == 0 && reorderedPowerOf2(n / 2));
    }
};