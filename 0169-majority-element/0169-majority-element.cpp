class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt = 0;
        
        int n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            if(cnt == 0){
                el = nums[i];
                cnt = 1;
            }
            else if(el == nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        
        cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(el == nums[i]){
                cnt++;
            }
        }
        
        if(cnt > n/2){
            return el;
        }
        
        return -1;
    }
};