class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;

        for(int i = 0 ; i < k ; i++){
            while(d.size() > 0 && nums[d.back()] <= nums[i]){
                d.pop_back();
            }
            d.push_back(i);
        }

        for(int i = k ; i < nums.size() ; i++){
            ans.push_back(nums[d.front()]);

            while(d.size() > 0 && d.front() <= i-k){
                d.pop_front();
            }

            while(d.size() > 0 && nums[d.back()] <= nums[i]){
                d.pop_back();
            }

            d.push_back(i);
        }

        ans.push_back(nums[d.front()]);

        return ans;
    }
};