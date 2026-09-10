class Solution {
  private:
    int priority(char el){
        if(el == '^') return 3;
        else if(el == '*' || el == '/') return 2;
        else if(el == '+' || el == '-') return 1;
        else return -1;
    }
  public:
    string infixToPostfix(string& s) {
        int i = 0;
        string ans = "";
        stack<char> st;
        
        int n = s.length();
        while(i < n){
            char el = s[i];
            if((el >= 'A' && el <= 'Z') || 
                (el >= 'a' && el <= 'z') || 
                (el >= '0' && el <= '9'))
                {
                    ans = ans + el;
                }
            else if(el == '('){
                st.push(el);
            }
            else if(el == ')'){
                while(!st.empty() && st.top() != '('){
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && (priority(el) < priority(st.top()) || 
                (priority(el) == priority(st.top()) && el != '^'))){
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(el);
            }
            i++;
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        
        return ans;
    }
};
