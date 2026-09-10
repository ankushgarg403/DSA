class Solution {
  private:
    bool divisible(string &s, int digit)
    {
        int ans = 0;

        // Compute remainder using modular arithmetic
        for (int i = 0; i < s.length(); i++)
        {
            ans = (ans * 10 + (s[i] - '0')) % digit;
        }

        // If remainder is 0, the number is divisible
        return (ans == 0);
    }
  public:
    int divisibleByDigits(string& s) {
        bool divide[10] = {false};
        divide[1] = true;
        
        for(int i = 2 ; i <= 9 ; i++){
            if(divisible(s,i)){
                divide[i] = true;
            }
        }
        
        int res = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(divide[s[i] - '0']){
                res++;
            }
        }
        
        return res;
    }
};
