class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<bool> check1(n);
        vector<bool> check2(n);
        for(int i = 0 ; i < n ; i++){
            check1[i] = true;
            check2[i] = false;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == j){
                    continue;
                }
                if(mat[i][j] == 1 && i != j){
                    check1[i] = false;
                    break;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            bool flag = true;
            for(int j = 0 ; j < n ; j++){
                if(mat[j][i] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                check2[i] = true;
            }
        }
        
        
        
        for(int i = 0 ; i < n ; i++){
            if(check1[i] && check2[i]){
                return i;
            }
        }
        
        return -1;
    }
};