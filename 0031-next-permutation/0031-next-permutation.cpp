class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        // int maxi = *max_element(nums.begin() , nums.end());
        // if(nums[0] == maxi){
        //     sort(nums.begin(),nums.end());
        //     return;
        // }
        if(n == 1){
            return;
        }
        while(nums[i] >= nums[i+1]){
            i--;
            if(i < 0){
                reverse(nums.begin(), nums.end());
                return;
            }
        }
        if(i >= 0){
            int j = n-1;
            while(nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i] , nums[j]);
            i++;
        }

        int j = n-1;
        while(j > i){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};