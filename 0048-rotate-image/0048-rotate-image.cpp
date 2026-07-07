class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int row = 0 ; row < n ; row++){
            int col = row;
            for(; col < n ; col++){
                if(!(row == col)){
                    swap(matrix[row][col] , matrix[col][row]);
                }
            }
        }
        int i = 0;
        int j = n - 1;
        while(i <= j){
            int row = 0;
            for( ; row < n ; row++){
                swap(matrix[row][i] , matrix[row][j]);
            }
            i++;
            j--;
        }
    }
};