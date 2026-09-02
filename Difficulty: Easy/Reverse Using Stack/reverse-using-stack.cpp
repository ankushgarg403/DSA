class Solution {
  public:
    string reverse(const string& S) {
        stack<char> st;
        string ans;
        
        for(int i = 0 ; i < S.length() ; i++){
            st.push(S[i]);
        }
        
        while(!st.empty()){
            char ch = st.top();
            
            ans.push_back(ch);
            st.pop();
            
        }
        return ans;
    }
};