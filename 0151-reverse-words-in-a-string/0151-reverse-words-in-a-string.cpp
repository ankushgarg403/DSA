class Solution {
private:
    void reverse(vector<string> &s){
        int i = 0;
        int j = s.size() - 1;
        while(j > i){
            swap(s[i] , s[j]);
            i++;
            j--;
        }
    }
public:
    string reverseWords(string s) {
        vector<string> ans;
        string temp;

        for(int i = 0 ; i <= s.length() ; i++){
            if(s[i] == ' ' || i >= s.length()){
                if(temp.length() > 0)
                    ans.push_back(temp);
                temp = "";
                continue;
            }
            temp = temp + s[i];
        }

        reverse(ans);

        string finall = ans[0];
        for(int i = 1 ; i < ans.size() ; i++){
            if(ans[i] != " ")
                finall = finall + " " + ans[i];
        }

        return finall;

        

    }
};