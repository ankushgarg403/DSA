class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        sort(begin(nums),end(nums));
        for ( int i = 0 ; i < (nums.size() - 1) ; i++){
            int key = nums[i];
            int counter = 1;
            if (nums[i+1] == key){
                counter++;
                nums[i+1] = -12-i;
            }
            if (counter == 2){
                ans.push_back(key);
            }
        }
        return ans;
    }
};