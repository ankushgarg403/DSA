class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int red = 0;
        int blue = n-1;
        int white = 0;

        while(white <= blue){
            if(nums[white] == 0){
                swap(nums[white],nums[red]);
                white++;
                red++;
            }
            else if(nums[white] == 1){
                white++;
            }
            else{
                swap(nums[white],nums[blue]);
                blue--;
            }
        }
    }
};