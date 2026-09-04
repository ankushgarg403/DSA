class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> ans;

        int max = *max_element(nums.begin() , nums.end());
        vector<bool> prime(max+1,true);
        prime[0] = prime[1] = false;
        for(int i = 2 ; i < max ; i++){
            if(prime[i]){
                for(int j = i*i ; j <= max ; j = j + i){
                    prime[j] = false;
                }
            }
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(prime[nums[i]]){
                ans.push_back(i);
            }
        }

        int distance = *max_element(ans.begin() , ans.end()) - 
                       *min_element(ans.begin() , ans.end());

        return distance;
    }
};