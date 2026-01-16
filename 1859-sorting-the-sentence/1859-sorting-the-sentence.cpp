class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);

        int count = 0, index = 0;
        int n = s.size();
        string temp = "";
;
        while(index < n){
            if(s[index] == ' '){
                int m = temp.size();
                int pos = temp[m-1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                index++;
                count++;
                temp.clear(); // for storing the next string
            }
            // if not equal to ' '
            else{
                temp += s[index];
                index++;
            }
        }

        // it is for last string because there is no space condition for last one string
        int m = temp.size();
        int pos = temp[m-1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;
        temp.clear();

        for(int i = 1; i <= count; i++){
            temp += ans[i];
            temp += ' ';
        }

        // remove the last space from temp string
        temp.pop_back();

        return temp;
    }
};