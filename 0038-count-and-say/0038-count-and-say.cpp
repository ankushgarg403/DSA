class Solution {
private:
    string solve(int n , string s){
        if(n == 1){
            return s;
        }
        
        s = solve(n-1,s);

        string ans = "";
        int count = 1;

        for(int i = 0 ; i < s.length()-1 ; i++){
            if(s[i] == s[i+1]){
                count++;
            }
            else{
                ans.push_back(count + '0');
                ans.push_back(s[i]);
                count = 1;
            }
        }
        ans.push_back(count + '0');
        ans.push_back(s[s.length() - 1]);

        return ans;
    }
public:
    string countAndSay(int n) {

        return solve(n,"1");
    }
};