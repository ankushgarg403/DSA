class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        vector<int> ans;
        
        int total = mat.size() * mat[0].size();
        
        int srow = 0;
        int erow = mat.size() - 1;
        int scol = 0;
        int ecol = mat[0].size() - 1;
        
        int count = 0;
        
        while(total > count){
            
            for(int i = scol ; total > count && i <= ecol ; i++){
                ans.push_back(mat[srow][i]);
                count++;
            }
            srow++;
            
            for(int i = srow ; total > count && i <= erow ; i++){
                ans.push_back(mat[i][ecol]);
                count++;
            }
            ecol--;
            
            for(int i = ecol ; total > count && i >= scol ; i--){
                ans.push_back(mat[erow][i]);
                count++;
            }
            erow--;
            
            for(int i = erow ; total > count && i >= srow ; i--){
                ans.push_back(mat[i][scol]);
                count++;
            }
            scol++;
            
        }
        
        return ans;
    }
};