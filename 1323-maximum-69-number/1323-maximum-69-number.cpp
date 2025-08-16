class Solution {
public:
    // first 6 at idx = 0 then 6 at idx = 2 that's the last six
    int maximum69Number (int num) {
        int idxOfSix = -1;
        int countIdx = 0;

        int temp = num;

        while(temp > 0){
            int rem = temp % 10;

            if(rem == 6){
                idxOfSix = countIdx;
            }

            temp /= 10;
            countIdx++;
        }

        if(idxOfSix == -1)
        return num;

        return num + 3 * pow(10, idxOfSix);
    }
};