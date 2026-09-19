class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);

        int i = 0;
        int j = s.length()-1;

        while(j > i){
            if(s[j] != s[i]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};