class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 1;
        // vector<int> ans;
        while(i < nums.size()-1){
            if(j > nums.size() - 1){
                i++;
                j = i+1;
            }
            if(nums[i] + nums[j] == target){
                return {i,j};
            }
            else{
                j++;
            }
        }
        return {};
    }
};