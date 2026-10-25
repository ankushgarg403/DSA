class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int curr_node = nums[0];
        for(int i : nums){
            if(count == 0) curr_node = i;
            if(i == curr_node) count++;
            else{
                count--;
            }
        }
        return curr_node;
    }
};