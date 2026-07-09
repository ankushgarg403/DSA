class Solution {
  public:
    vector<vector<int>> sortedMatrix(vector<vector<int>> mat) {
        vector<int> temp;
        int n = mat.size();
        int i = 0;
        int j = 0;
        while(i < n ){
            temp.push_back(mat[i][j]);
            // j++;
            if(j == n-1 && i < n){
                i++;
                j = -1;
            }
            j++;
        }
        sort(temp.begin() , temp.end());
        int count = 0;
        while(n*n > count){
            mat[count/n][count%n] = temp[count];
            count++;
        }
        return mat;
    }
};