class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        string maxGood = "";

        string str = "";
        for(int i = 0; i < n-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                str = string(3, num[i]);

                if(maxGood.size() == 0)
                maxGood += str;
                
                if(stoi(str) > stoi(maxGood))
                maxGood = str;
            }
        }

        return maxGood;
    }
};