class Solution {
  private:
    void reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        
        int num = st.top();
        st.pop();
        
        reverse(st);
        
        st.push(num);
    }
  public:
    void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        stack<int> st;
        
        for(int i = 0 ; i < n/2 ; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        for(int i = 0 ; i < n/2 ; i++){
            q.push(q.front());
            q.pop();
        }
        
        for(int i = 0 ; i < n/2 ; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
            
            q.push(q.front());
            q.pop();
        }
    }
};