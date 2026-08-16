class Solution {
  private:
    void solve(vector<int> arr , string output , int i , vector<string>& ans , string mapping[]){
        int n = arr.size();
        if(i >= n){
            ans.push_back(output);
            return;
        }
        
        string el = mapping[arr[i]];
        for(int j = 0 ; j < el.length() ; j++){
            output.push_back(el[j]);
            solve(arr,output,i+1,ans,mapping);
            output.pop_back();
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        int i = 0;
        vector<string> ans;
        string output = "";
        
        string mapping[10] = {"","","abc","def","ghi","jkl","mno",
        "pqrs","tuv","wxyz"};
        int k = 0;
        for (int j = 0 ; j < arr.size() ; j++){
            if(arr[j] > 1){
                arr[k] = arr[j];
                k++;
            }
        }
        arr.resize(k);
        
        solve(arr,output,i,ans,mapping);
        
        return ans;
    }
};