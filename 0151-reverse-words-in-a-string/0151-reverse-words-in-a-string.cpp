class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string word;
        string result = "";
        while(ss >> word){
            if(result == ""){
                result = word;
            }
            else{
                result = word + " " + result;
            }
        }

        return result;
    }
};