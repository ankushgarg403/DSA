class Solution {
  public:
    string preToPost(string &s) {
        stack<string> st;

        int n = s.length();

        int i = n-1;
        while(i >= 0){
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

                string temp = b + a + el;

                st.push(temp);

            }
            i--;
        }
        string ans = st.top();
        return ans;
    }
};