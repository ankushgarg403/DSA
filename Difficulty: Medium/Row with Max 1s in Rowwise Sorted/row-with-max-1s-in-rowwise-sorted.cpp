class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        
        int row = arr.size();
        int col = arr[0].size();
        
        int ans = -1;
        int count2 = 0; 
        for(int i = 0 ; i < row ; i++){
            int count1 = 0;
            for(int j = 0 ; j < col ; j++){
                if(arr[i][j] == 1){
                    count1++;
                }
            }
            if(count1 > count2){
                count2 = count1;
                ans = i;
            }
        }
        return ans;
    }
};