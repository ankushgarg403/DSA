class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        for(int row = 0 ; row < matrix.size() ; row++){
            for(int col = 0 ; col < matrix[0].size() ; col++){
                temp.push_back(matrix[row][col]);
            }
        }
        sort(temp.begin() , temp.end());
        return temp[k-1];
    }
};