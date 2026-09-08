class Solution {
  private:
    void reverse(vector<int>& arr , int s , int e){
        while(e > s){
            swap(arr[s],arr[e]);
            s++;
            e--;
        }
    }
  public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d=d%n;
        reverse(arr,0,n-1);
        reverse(arr,0,n-d-1);
        reverse(arr,n-d,n-1);
    }
};