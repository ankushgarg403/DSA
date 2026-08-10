class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        int arr[26] = {0};
        for(int i = 0 ; i < s.length() ; i++){
            int ch = s[i];
            int num = 0;
            num = ch - 'a';
            arr[num]++;
        }
        int maxi = -1;
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                ans = i;
            }
        }
        
        return ans+'a';
    }
};