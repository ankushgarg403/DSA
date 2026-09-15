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
    vector<int> ng(vector<int> arr){
        int n = arr.size();

        stack<int> st;
        st.push(-1);

        vector<int> ans(n);
        int i = n-1;
        while(i >= 0){
            int el = arr[i];
            while(st.top() != -1 && arr[st.top()] <= el){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
            i--;
        }

        return ans;
    }
    vector<int> pg(vector<int> arr){
        int n = arr.size();

        stack<int> st;
        st.push(-1);

        vector<int> ans(n);
        int i = 0;
        while(i < n){
            int el = arr[i];
            while(st.top() != -1 && arr[st.top()] < el){
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
            i++;
        }

        return ans;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevsmaller(n);
        prevsmaller = ps(nums);

        vector<int> nextsmaller(n);
        nextsmaller = ns(nums);
        
        vector<int> prevgreater(n);
        prevgreater = pg(nums);

        vector<int> nextgreater(n);
        nextgreater = ng(nums);

        // string mod = (int)("10e9 + 7");
        // long long mod = 1e9 + 7;  
        int i = 0;
        long long sum1 = 0;
        long long sum2 = 0;
        while(i < n){
            if(nextsmaller[i] == -1){
                nextsmaller[i] = n;
            }
            if(nextgreater[i] == -1){
                nextgreater[i] = n;
            }

            sum1 = sum1 + (1ll * nums[i]*(i-prevsmaller[i])*(nextsmaller[i]-i));
            sum2 = sum2 + (1ll * nums[i]*(i-prevgreater[i])*(nextgreater[i]-i));
            i++;
        }
        return sum2-sum1;
    }
};