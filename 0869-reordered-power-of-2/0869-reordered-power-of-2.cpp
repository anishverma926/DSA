class Solution {
public:
    string getSortedStr(int n){
        string str = to_string(n);
        sort(str.begin(), str.end());

        return str;
    }

    bool reorderedPowerOf2(int n) {
        string s = getSortedStr(n);

        for(int p = 0; p <= 29; p++){
            if(s == getSortedStr(1 << p))
            return true;
        }

        return false;
    }
};