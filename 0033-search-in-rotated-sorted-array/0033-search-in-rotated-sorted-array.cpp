class Solution {
private:
    int pivot(vector<int>& nums){
        int s = 0;
        int e = nums.size() - 1;

        while(e > s){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[s] <= nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }

        return s;
    }
    int solve(vector<int>& nums, int target , int s , int e){
        while(e >= s){
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;

        int p = pivot(nums);
        if(nums[p] == target) return p;

        if(target < nums[0]){
            return solve(nums,target,p+1,nums.size()-1);
        }
        else{
            return solve(nums,target,0,p-1);
        }
    }
};