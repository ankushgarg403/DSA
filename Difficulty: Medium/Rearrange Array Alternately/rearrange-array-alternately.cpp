class Solution {
  public:
    void rearrange(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        int arr1[n/2];
        int arr2[n - (n/2)];
        
        for(int i = 0 ; i < n/2 ; i++){
            arr1[i] = arr[i];
        }
        
        int j = 0;
        for(int i = n-1 ; i >= n/2 ; i--){
            arr2[j] = arr[i];
            j++;
        }
        
        j = 0;
        for(int i = 1 ; i < n ; i = i + 2){
            arr[i] = arr1[j];
            j++;
        }
        
        j = 0;
        for(int i = 0 ; i < n ; i = i + 2){
            arr[i] = arr2[j];
            j++;
        }
        return;
    }
};