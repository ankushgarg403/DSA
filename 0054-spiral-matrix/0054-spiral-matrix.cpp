class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int total = matrix.size() *matrix[0].size();
        int sr = 0;
        int sc = 0;
        int er = matrix.size()-1;
        int ec = matrix[0].size()-1;

        int count = 0;
        while(total > count){
            for(int i = sc ;count < total && i <= ec ; i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            for(int i = sr ;count < total && i <= er ; i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            for(int i = ec ;count < total && i >= sc ; i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            for(int i = er ;count < total && i >= sr ; i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
        }
        return ans;
    }
};