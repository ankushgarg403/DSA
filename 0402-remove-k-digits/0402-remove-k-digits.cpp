class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;

        for(int i = 0 ; i < n ; i++){
            char el = num[i];
            while(!st.empty() && k > 0 && (st.top()-'0') > (el-'0')){
                st.pop();
                k--;
            }

            st.push(el);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        while(!ans.empty() && ans.back() == '0'){
            ans.pop_back();
        }

        int i = 0;
        int j = ans.length() - 1;
        while(j > i){
            swap(ans[i++] , ans[j--]);
        }

        if(ans.empty()) return "0";
        return ans;
    }
};