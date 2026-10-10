class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m1;
        map<char,char> m2;

        int len = s.length();


        if(len != t.length()) return false;

        for(int i = 0 ; i < s.length() ; i++){
            char el = s[i];
            // if(m.find(el) != m.end())
            if(m1[el]){
                if(m1[el] == t[i]){
                    continue;
                }
                return false;
            }
            else{
                m1[el] = t[i];
            }
        } 

        for(int i = 0 ; i < s.length() ; i++){
            char el = t[i];
            // if(m.find(el) != m.end())
            if(m2[el]){
                if(m2[el] == s[i]){
                    continue;
                }
                return false;
            }
            else{
                m2[el] = s[i];
            }
        } 

        return true;
    }
};