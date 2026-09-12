class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        vector<string> ans;
        
        string word;

        while (ss >> word) {
            ans.push_back(word);             
        }

        // return ans[1];
        
        int n = ans.size();

        stringstream result;
        result << ans[n-1];

        for(int i = n - 2 ; i >= 0 ; i--){
            result << " " << ans[i] ;
        }

        // string result = ss.str();

        return result.str();

    }
};