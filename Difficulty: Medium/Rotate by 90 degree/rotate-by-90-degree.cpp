class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0 ; i < n-1 ; i++){
            int j = i+1;
            for( ; j < n ; j++){
                swap(mat[i][j] , mat[j][i]);
            }
        }
        
        int s = 0;
        int e = n-1;
        while(e > s){
            int i = 0;
            for( ; i < n ; i++){
                swap(mat[s][i] , mat[e][i]);
            }
            s++;
            e--;
        }
        
        return;
    }
};
