class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        
        int j = min_element(nums.begin() , nums.end()) - nums.begin();
        int k = max_element(nums.begin() , nums.end()) - nums.begin();


        int right = max(k,j);
        int left = min(k,j);
        
        int front = right + 1;
        int back = n-left;

        int both = left+1 + n-right;

        return min({front,back,both});
    }
};