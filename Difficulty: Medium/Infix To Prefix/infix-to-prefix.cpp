class Solution {
  private:

    int priority(char el){
        if(el == '^') return 3;
        else if(el == '*' || el == '/') return 2;
        else if(el == '+' || el == '-') return 1;
        else return -1;
    }
    
    string reverse(string &s){
        int start = 0;
        int end = s.length()-1;
        while(end > start){
            // if(s[end] == '(') s[end] = ')';
            // else if(s[end] == ')') s[end] = '(';
            // else if(s[start] == '(') s[start] = ')';
            // else if(s[start] == ')') s[start] = '(';
            
            swap(s[start] , s[end]);
            start++;
            end--;
            
        }
        return s;
    }
  public:
    string infixToPrefix(string &s) {
        s = reverse(s);
        
        int i = 0;
        stack<char> st;
        string ans = "";
        
        int n = s.length();
        
        while(n > i){
            char el = s[i];
            if((el >= 'A' && el <= 'Z') || 
                (el >= 'a' && el <= 'z') || 
                (el >= '0' && el <= '9'))
                {
                    ans = ans + el;
                }
            else if(el == ')'){
                st.push(el);
            }
            else if(el == '('){
                while(!st.empty() && st.top() != ')'){
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            
            else{
                if(el == '^'){
                    while(!st.empty() && priority(el) <= priority(st.top())){
                        ans = ans + st.top();
                        st.pop();
                    }
                }
                else{
                    while(!st.empty() && priority(el) < priority(st.top())){
                        ans = ans + st.top();
                        st.pop();
                    }
                }
                st.push(el);
            }
            i++;
        }
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        ans = reverse(ans);
        return ans;
    }
};
