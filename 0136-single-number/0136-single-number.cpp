class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size();
        // int sum = 0;
        
        for(int i = 1 ; i < nums.size() ; i++){
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};