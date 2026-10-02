class Solution {
public:
    bool isPalindromic(string s) {
        int i = 0;
        int j = s.length() - 1;

        while(j >= i){
            for(int k = 7 ; k >= 0 ; k--){
                int a = (s[i] >> k)&1;
                int b = (s[j] >> (7-k))&1;

                if(a != b) return false;
            }
            j--;
            i++;
        }

        return true;
    }
};