class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        // int n = nums.size();
        for(int i = 0 ; i < nums.size() ;){
            if(!m[nums[i]]){
                m[nums[i]] = 1;
                i++;
            }
            else if(m[nums[i]] >= 2){
                nums.erase(nums.begin() + i);
            }
            else{
                m[nums[i]]++;
                i++;
            }
        }
        return nums.size();
    }
};
// class Solution{
// public:
//     int removeDuplicates(vector<int>& nums) {
//         unordered_map<int, int> m;

//         int i = 0;

//         while (i < nums.size()) {

//             if (m.find(nums[i]) == m.end()) {
//                 m[nums[i]] = 1;
//                 i++;
//             }
//             else if (m[nums[i]] >= 2) {
//                 nums.erase(nums.begin() + i);
//             }
//             else {
//                 m[nums[i]]++;
//                 i++;
//             }
//         }

//         return nums.size();
//     }
// };