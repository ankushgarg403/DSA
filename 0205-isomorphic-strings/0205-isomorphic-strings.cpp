class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(200,0);
        vector<int> m2(200,0);

        int len = s.length();


        if(len != t.length()) return false;

        for(int i = 0 ; i < len ; i++){
            if(m1[s[i]] != m2[t[i]]){
                return false;
            }

            m1[s[i]] = i+1;
            m2[t[i]] = i+1;
        }

        return true;
    }
};