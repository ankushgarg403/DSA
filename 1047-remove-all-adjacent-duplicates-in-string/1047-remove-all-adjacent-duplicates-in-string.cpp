class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        while((i < s.length() - 1) && (s.length() >= 2)){
            if(s[i] == s[i+1]){
                s.erase(i,2);
                if(i != 0)
                    i = i-1;
            }
            else{
                i++;
            }
        }
        return s;
    }
};