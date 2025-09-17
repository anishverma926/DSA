class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();

        int i = 0;
        int j = n - 1;

        while(i <= j){
            if(s[i] != s[j])
            return false;

            i++;
            j--;
        }

        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i < n -1; i++){
            int value = n;
            string str = "";

            while(value > 0){
                str.push_back((value % i + '0'));
                value /= i;
            }

            reverse(str.begin(), str.end());
            if(!isPalindrome(str))
            return false;
        }

        return true;
    }
};