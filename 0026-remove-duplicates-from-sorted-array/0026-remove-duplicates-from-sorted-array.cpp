class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();


        for(int i = 0 ; i < n ; i++){
            int j = i+1;
            bool flag = false;
            while(j < n && nums[i] == nums[j]){
                j++;
                flag = true;
            }
            if(flag){
                nums.erase(nums.begin()+i+1,nums.begin()+j);
            }
            n = nums.size();
        }

        return nums.size();
    }
};