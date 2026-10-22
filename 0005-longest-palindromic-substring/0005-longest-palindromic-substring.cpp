class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;
        int start = 0;

        int n = s.length();

        for(int i = 0 ; i < n ; i++){

            int l = i;
            int r = i+1;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > len){
                    start = l;
                    len = r-l+1;
                }
                r++;
                l--;
            }

            l = i;
            r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > len){
                    start = l;
                    len = r-l+1;
                }
                r++;
                l--;
            }
        }

        return s.substr(start,len);
    }
};