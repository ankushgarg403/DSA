class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int counter = 0;
        for(int i = 0 ; i < s.length() ; i++){
            char el = s[i];
            if(el == '('){
            st.push(el);
            }
            else{
            if(!st.empty()){
                st.pop();
            }
            else{
                counter++;
            }
            }
        }
        while(!st.empty()){
            counter++;
            st.pop();
        }

        return counter;
    }
};