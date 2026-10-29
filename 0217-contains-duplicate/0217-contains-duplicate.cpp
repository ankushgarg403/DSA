class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> m;

        for(int i = 0 ; i < n ; i++){
            int el = nums[i];
            if(m.find(el) != m.end()){
                return true;
            }
            m[el] = 1;
        }

        return false;
    }
};