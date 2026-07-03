class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // int ans = -1;
        int s = 1;
        int e = arr.size() - 2;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]){
                return mid;
            }
            else if(arr[mid] > arr[mid+1]){
                e = mid - 1;
            }
            else if(arr[mid] < arr[mid+1]){
                s = mid + 1; 
            }
        }
        return -1;
    }
};