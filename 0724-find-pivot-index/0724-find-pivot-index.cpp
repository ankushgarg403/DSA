class Solution {
private:
    int solve(int arr[] , int totalsum , long int left , int s , int n){
        if(s >= n){
            return -1;
        }
        // for(int i = 0 ; i < n ; i++){
        //     totalsum += arr[i];
        // }
        int right = totalsum - left - arr[s];
        if(right == left){
            return s;
        }
        left += arr[s];
        s++;
        return solve(arr , totalsum , left , s , n);
    }
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            totalsum += nums[i];
        }
        int n = nums.size();
        long int left = 0;
        int ans = solve(nums.data() , totalsum , left , 0 , n);
        return ans;
    }
};