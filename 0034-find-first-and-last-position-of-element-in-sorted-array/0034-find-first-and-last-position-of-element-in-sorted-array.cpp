class Solution {
private: 
    int first(vector<int>& nums , int target){
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;
        while(e >= s){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid - 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans; 
    }
    int second(vector<int>& nums , int target){
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;
        while(e >= s){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid + 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans; 
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums,target);
        int s = second(nums,target);

        return {f,s};
    }
};