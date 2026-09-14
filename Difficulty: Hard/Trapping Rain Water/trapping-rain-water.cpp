class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        int total = 0;
        
        vector<int> prefix(n);
        vector<int> sufix(n);
        
        prefix[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = max(prefix[i-1] , arr[i]);
        }
        
        sufix[n-1] = arr[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            sufix[i] = max(sufix[i+1] , arr[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            int leftmax = prefix[i];
            int rightmax = sufix[i];
            if(arr[i] < leftmax && arr[i] < rightmax){
                total += min(leftmax,rightmax) - arr[i];
            }
        }
        
        return total;
    }
};