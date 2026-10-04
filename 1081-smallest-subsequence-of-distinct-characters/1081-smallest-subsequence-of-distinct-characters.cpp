class Solution {
public:
    string smallestSubsequence(string s) {
        int arr[26] = {0};

        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];
            arr[ch - 'a']++;
        }

        bool visited[26] = {false};

        string st = "";
        for(char ch : s){
            arr[ch - 'a']--;

            if (visited[ch - 'a']) {
                continue;
            }

            while(!st.empty() &&
                  st.back() > ch &&
                  arr[st.back() - 'a'] > 0){
                    visited[st.back() - 'a'] = false;
                    st.pop_back();
                }
            
            st.push_back(ch);
            visited[ch - 'a'] = true;
        }
        return st;
    }
};