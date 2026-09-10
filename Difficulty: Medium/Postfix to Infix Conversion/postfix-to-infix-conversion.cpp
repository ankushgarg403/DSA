#include<stack>
#include<string>
class Solution {
  public:
    string postToInfix(string &s) {
        int i = 0;
        stack<string> st;
        
        int n = s.length();
        while(n > i){
            char el = s[i];
            // string ch = to_string(s[i]);
            string ch(1, s[i]);
            if((el >= 'A' && el <= 'Z') || 
                (el >= 'a' && el <= 'z') || 
                (el >= '0' && el <= '9'))
                {
                    st.push(ch);
                }
            
            else{
                string b = st.top();
                st.pop();
                
                string a = st.top();
                st.pop();
                
                string temp = '(' + a + el + b + ')';
                
                st.push(temp);
                
            }
            i++;
        }
        string ans = st.top();
        return ans;
    }
};