class Solution {
public:
    long long sumAndMultiply(int n) {

        if(n == 0) return 0;

        string s = to_string(n);

        int len = s.length();

        for(int i = 0 ; i < len ; i++){
            if(s[i] == '0'){
                s.erase(i,1);
                len = s.length();
                i--;
            }
        }

        int sum = 0;
        for(int i = 0 ; i < s.length() ; i++){
            sum = sum + (s[i] - '0');
        }

        long long ans = stoi(s);

        // if(ansn*sum >= INT_MAX) return INT_MAX;

        return ans*sum;
        
    }
};