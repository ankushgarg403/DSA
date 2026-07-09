class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        int n = matrix.size();
        int i = 0;
        int j = 0;
        while(i < n ){
            temp.push_back(matrix[i][j]);
            // j++;
            if(j == n-1 && i < n){
                i++;
                j = -1;
            }
            j++;
        }
        sort(temp.begin() , temp.end());
        return temp[k-1];
    }
};