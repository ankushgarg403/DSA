class Solution {
  private:
    void solve(vector<vector<int>> maze , string output , 
    int i , int j , vector<string>& ans){
        if((maze.size()-1 == i) && (maze.size()-1 == j)){
            ans.push_back(output);
            return;
        }
        
        if(i < 0 || j < 0 || i >= maze.size() || j >= maze.size()) return;
        
        if(maze[i][j] == 0){
            return;
        }
        
        maze[i][j] = 0;
        
        // Up
        output.push_back('U');
        solve(maze,output,i-1,j,ans);
        output.pop_back();
        
        // Down
        output.push_back('D');
        solve(maze,output,i+1,j,ans);
        output.pop_back();
        
        // Right
        output.push_back('R');
        solve(maze,output,i,j+1,ans);
        output.pop_back();
        
        // Left
        output.push_back('L');
        solve(maze,output,i,j-1,ans);
        output.pop_back();
        
        maze[i][j] = 1;
        
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        string output = "";
        
        int n = maze.size();
        if(n == 0 || maze[0][0] == 0 || maze[n-1][n-1]==0){
            return ans;
        }
        
        int i = 0;
        int j = 0;
        // string mapping[2] = {"D" , "R"};
        
        solve(maze,output,i,j,ans);
        
        sort(ans.begin() , ans.end());
        
        return ans;
    }
};