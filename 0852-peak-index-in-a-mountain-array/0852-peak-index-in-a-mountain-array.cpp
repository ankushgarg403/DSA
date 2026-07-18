class Solution {
private:
    int solve(int arr[] , int s , int e ){
        int mid = e + (s - e)/2;
        if((arr[mid] > arr[mid+1]) && (arr[mid] > arr[mid-1])){
            return mid;
        }
        else if(arr[mid] > arr[mid+1]){
            return solve(arr , 0 , mid );
        }
        return solve(arr , mid , e);
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        return  solve(arr.data() , 0 , n-1);
    }
};