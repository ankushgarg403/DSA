class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        int n = nums.size();

        vector<int> ans;

        int i = 0;
        int j = 1;
        int el = 0;
        while(j < n){
            if(nums[i] == nums[j]){
                el = nums[i];
                ans.push_back(nums[i]);
                break;
            }
            i++;
            j++;
        }
        int sum = n*(n+1)/2;
        int sum2 = 0;
        for(int i = 0 ; i < n ; i++){
            sum2 = sum2 + nums[i];
        }
        ans.push_back(sum - sum2 + el);

        return ans;
    }
};