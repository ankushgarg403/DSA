class Solution {
private:
char tolowercase(char s){
    if((s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')){
        return s;
    }
    else {
        char temp = s - 'A' + 'a';
        return temp;
    }
}
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int start = 0;
        int end = len - 1;
        while(start <= end){
            if(!(tolowercase(s[start]) >= 'a' && tolowercase(s[start]) <= 'z')){
                if(!(s[start] >= '0' && s[start] <= '9')){
                    // if(s[start] == '\0')
                        start++;
                        continue;
                }
            }
            if(!(tolowercase(s[end]) >= 'a' && tolowercase(s[end]) <= 'z')){
                if(!(s[end] >= '0' && s[end] <= '9')){
                    // if(s[end] == '\0')
                        end--;
                        continue;
                }
            }

            if(tolowercase(s[start]) != tolowercase(s[end])){
                return false;
            }
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};