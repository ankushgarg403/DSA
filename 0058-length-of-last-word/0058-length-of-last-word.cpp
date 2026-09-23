class Solution {
private:
    int removespace(string &s){
        int n = s.length();
        int i = n-1;
        int count = 0;

        while(i >= 0 && s[i] == ' '){
            i--;
        }
        while(i >= 0 && s[i] != ' '){
            count++;
            i--;
        }

        return count;

    }
public:
    int lengthOfLastWord(string s) {
        if(s.length() == 1){

            return 1;
        }
        int count = removespace(s);
        return count;
    }
};