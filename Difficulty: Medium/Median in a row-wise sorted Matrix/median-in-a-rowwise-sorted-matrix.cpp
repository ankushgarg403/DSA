class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        vector<int> temp;
        int n = mat.size();
        int m = mat[0].size();
        int i = 0;
        int j = 0;
        while(i < n ){
            temp.push_back(mat[i][j]);
            // j++;
            if(j == m-1 && i < n){
                i++;
                j = -1;
            }
            j++;
        }
        sort(temp.begin() , temp.end());
        return temp[(m*n)/2];
    }
};
