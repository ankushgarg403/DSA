class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.length())
            return s;

        string ans = "";
        int n = s.length();

        int len = 2*(numRows - 1);
    
        for(int i = 0 ; i < numRows ; i++){
            for(int j = 0 ; j + i < n ; j += len){
                ans += s[i+j];

                int second = j + len - i;

                if(i != 0 && i != numRows-1 && second < n){
                    ans += s[second];
                }

            }
        }

        return ans;
    }
};