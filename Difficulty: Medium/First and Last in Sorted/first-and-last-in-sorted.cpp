class Solution {
  private:
    int firstoccurance(vector<int>& arr, int x ){
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        
        while(e >= s){
            int mid = s + (e-s)/2;
            if(arr[mid] == x){
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
    int lastoccurance(vector<int>& arr, int x ){
        int s = 0;
        int e = arr.size()-1;
        int ans = -1;
        
        while(e >= s){
            int mid = s + (e-s)/2;
            if(arr[mid] == x){
                ans = mid;
                s = mid+1;
            }
            else if(arr[mid] > x){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
  public:
    vector<int> find(vector<int>& arr, int x) {
        int first = firstoccurance(arr,x);
        int last = lastoccurance(arr,x);
        
        vector<int> ans;
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
};