class Solution {
  private:
    vector<int> pge(vector<int> &arr){
        stack<int> st;
        st.push(-1);
        
        int n = arr.size();
        
        vector<int> ans(n);
        for(int i = 0 ; i < n ; i++){
            int el = arr[i];
            while(st.top() != -1 && arr[st.top()] <= el){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
        }
        
        return ans;
    }
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        int i = n-1;
        
        vector<int> ans(n);
        
        vector<int> prevgreater(n);
        prevgreater = pge(arr);
        
        while(i >= 0){
            // int el = arr[i];
            
            int j = prevgreater[i];
            
            ans[i] = i - j;
            i--;
        }
        return ans;
    }
};