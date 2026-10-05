class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if(s == goal){
                return true;
            }
            char ch = s[j];
            s.erase(s.begin() + j);
            s.push_back(ch);
        }
        return false;
    }
};