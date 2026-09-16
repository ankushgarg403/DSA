class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = -1;

        int n = heights.size();
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxarea = max(heights[el] * (nse-pse-1) , maxarea);
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = n;
            int el = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea , (nse-pse-1)*heights[el]);
        }

        return maxarea;
    }
};