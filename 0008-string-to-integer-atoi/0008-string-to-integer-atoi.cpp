class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        if(s.empty()) return 0;

        while(i < n && s[i] == ' '){
            i++;
        }

        if(i == n) return 0;

        int sign = 1;
        if(s[i] == '-'){
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;
        
        long long ans = 0;
        while(i < n && isdigit(s[i])){
            int el = s[i] - '0';
            ans = ans*10 + el;

            if(ans*sign >= INT_MAX) return INT_MAX;
            else if(ans*sign <= INT_MIN) return INT_MIN;

            i++;
        }

        return ans*sign;

        


    }
};