class Solution {
private:
    void solve(string digits , string output , int index , vector<string>& ans , string mapping[]){
        int n = digits.size();
        // Base case
        if(index >= n){
            ans.push_back(output);
            return;
        }

        // First
        string el = mapping[digits[index] - '0'];
        for(int i = 0 ; i < el.length() ; i++){
            output.push_back(el[i]);
            solve(digits , output , index+1 , ans , mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        if(digits.length() == 0){
            return ans;
        }
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        int index = 0;
        solve(digits,output,index,ans,mapping);

        return ans;
    }
};