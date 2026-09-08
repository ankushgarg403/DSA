class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        vector<int> ans;
        for(int i = 0 ; i < n - 1 ; ){
            if(arr[i] != arr[i+1]){
                ans.push_back(arr[i]);
                i++;
            }
            else{
                i = i + 2;
            }
        }
        
        if(arr[n-1] != arr[n-2])  ans.push_back(arr[n-1]);
        
        return ans;
    }
};