class Solution {
public:
    vector<int> getVectorCountFormat(int n){
        vector<int> vec(10, 0);

        while(n){
            vec[n%10]++;
            n /= 10;
        }

        return vec;
    }

    bool reorderedPowerOf2(int n) {
        vector<int> input = getVectorCountFormat(n);

        for(int p = 0; p <= 29; p++){
            if(input == getVectorCountFormat(1 << p))
            return true;
        }

        return false;
    }
};