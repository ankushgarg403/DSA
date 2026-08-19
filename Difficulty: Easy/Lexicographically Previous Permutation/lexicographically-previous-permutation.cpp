class Solution {
  public:
    string prevPermutation(string &s) {
        // code here
        int n = s.length();
        
        int i = n-2;
        
        while(i >= 0 && s[i] <= s[i+1]){
            i--;
        }
        
        if(i < 0){
            return "-1";
        }
        
        int j = n-1;
        
        while(s[j] >= s[i]){
            j--;
        }
        
        swap(s[i],s[j]);
        
        reverse(s.begin() + i + 1, s.end());
        // j = n-1;
        // i = i + 1;
        // while(j > i){
        //     swap(s[i++] , s[j--]);
        // }
        
        if(s[0] == '0'){
            return "-1";
        }
        
        return s;
        
    }
};