class Solution {
  public:
    stack<int> insertAtBottom(stack<int> &st, int x) {
        vector<int> s;
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        
        s.push_back(x);
        int len = s.size() - 1;
        
        while(len >= 0){
            st.push(s[len]);
            len--;
        }
        
        return st;
    }
};