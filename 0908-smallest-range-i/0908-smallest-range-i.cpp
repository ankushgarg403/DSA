class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_val = nums[0], max_val = nums[0];

        for (int x : nums) {

            min_val = min(min_val, x);

            max_val = max(max_val, x);

        }

        return max(0, max_val - min_val - 2 * k);

    }
};