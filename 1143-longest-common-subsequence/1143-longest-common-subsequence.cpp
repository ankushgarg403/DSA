class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<int> ans(text1.length(),0);

        int longest = 0;

        for(char c : text2){
            int currlen = 0;
            for(int i = 0 ; i < ans.size() ; i++){
                if(c == text1[i]){
                    longest++;
                }
            }
        }

        return longest;
    }
};