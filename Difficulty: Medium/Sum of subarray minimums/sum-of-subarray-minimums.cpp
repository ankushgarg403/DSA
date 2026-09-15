class Solution {
  private:
    vector<int> ns(vector<int> arr){
        int n = arr.size();
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        int i = n-1;
        while(i >= 0){
            int el = arr[i];
            while(st.top() != -1 && arr[st.top()] >= el){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
            i--;
        }
        
        return ans;
    }
    vector<int> ps(vector<int> arr){
        int n = arr.size();
        
        stack<int> st;
        st.push(-1);
        
        vector<int> ans(n);
        int i = 0;
        while(i < n){
            int el = arr[i];
            while(st.top() != -1 && arr[st.top()] > el){
                st.pop();
            }
            
            ans[i] = st.top();
            st.push(i);
            i++;
        }
        
        return ans;
    }
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        
        vector<int> prevsmaller(n);
        prevsmaller = ps(arr);
        
        vector<int> nextsmaller(n);
        nextsmaller = ns(arr);
        
        int i = 0;
        long long sum = 0;
        while(i < n){
            // if(prevsmaller[i] == -1){
            //     prevsmaller[i] = 0;
            // }
            if(nextsmaller[i] == -1){
                nextsmaller[i] = n;
            }
            
            sum += 1ll * arr[i]*(i-prevsmaller[i])*(nextsmaller[i]-i);
            i++;
        }
        
        return sum;
    }
};