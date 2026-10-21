class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> mini;
        vector<int> maxi;

        for(int i = 0 ; i < row ; i++){
            mini.push_back(*min_element(matrix[i].begin() , matrix[i].end()));
        }

        for(int i = 0 ; i < col ; i++){
            int m = -1;
            for(int j = 0 ; j < row ; j++){
                if(m < matrix[j][i]){
                    m = matrix[j][i];
                }
            }
            maxi.push_back(m);
        }

        // vector<int> ans;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == mini[i] &&
                    matrix[i][j] == maxi[j]) {
                    return {matrix[i][j]};
                }
            }
        }

        return {};
    }
};