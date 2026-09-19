class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        // vector<int> ans;

        int i = 0;
        int j = n-1;
        int ans = -1;
        while(j > i){
            ans = max(ans,min(height[i] , height[j])*(j-i));
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};