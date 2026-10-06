class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.length();
        
        string ans(n,' ');
        // for(int i = 0 ; i < s.length() ; i++){
        //     ans.push_back('a');
        // }

        for(int i = 0 ; i < indices.size() ; i++){
            // char ch = s[i];
            ans[indices[i]] = s[i];
        }

        return ans;
    }
};