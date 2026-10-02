#include<bitset>
class Solution {
public:
    bool isPalindromic(string s) {
        int n = s.length();
        string st = "";
        for(int i = 0 ; i < n ; i++){
            char ch = s[i];
            int asciivalue = int(ch);
            bitset<8> binary(asciivalue);
            st = st + binary.to_string();
        }

        int i = 0;
        int j = st.length()-1;
        while(j > i){
            if(st[i] != st[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};