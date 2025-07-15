class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o'|| ch == 'u')
        return true;

        return false;
    }

    bool isValid(string word) {
        int n = word.size();
        bool hasVowel = false;
        bool hasConst = false;

        if(n < 3)
        return false;
        
        for(int i = 0 ; i < n; i++){
            char ch = word[i];

            if(isalpha(ch)){
                if(isVowel(word[i])){
                    hasVowel = true;
                }

                else{
                    hasConst = true;
                }
            }

            else if(!isdigit(ch)){
                return false;
            }
            
        }

        return hasVowel && hasConst;
    }
};