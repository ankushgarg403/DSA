class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        st.push(-1);
        
        int n = arr.size();
        
        vector<int> ans(n);
        
        int i = n - 1;
        
        while(i >= 0){
            int el = arr[i];
            while(st.top() <= el && st.top() != -1){
                // if(st.top() == -1){
                //     // ans[i] = -1;
                //     // st.push(el);
                //     break;
                // }
                st.pop();
            }
            ans[i] = st.top();
            st.push(el);
            i--;
        }
        
        return ans;
    }
};