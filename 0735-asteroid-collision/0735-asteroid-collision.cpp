class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;

        int i = 0;

        while(i < n){
            int el = asteroids[i];
            if(el > 0){
                st.push(el);
                i++;
                continue;
            }

            else{
                bool alive = true;
                while(!st.empty() && st.top() > 0 && abs(el) > st.top()){
                    st.pop();
                }

                if(!st.empty() && st.top() > 0){
                    if(abs(el) == st.top()){
                        st.pop();
                        alive = false;
                    }
                    else if(abs(el) < st.top()){
                        alive = false;
                    }
                }

                if(alive){
                    st.push(el);
                }
            }
            i++;
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        n = ans.size();
        i = 0;
        int j = n-1;

        while(j > i){
            swap(ans[i],ans[j]);
            i++;
            j--;
        }

        return ans;
    }
};