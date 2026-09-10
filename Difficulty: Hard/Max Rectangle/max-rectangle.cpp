class Solution {
  private:
    
    vector<int> nextsmallerel(vector<int>& arr , int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1 ; i >= 0 ; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }

    vector<int> prevsmallerel(vector<int>& arr , int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0 ; i < n ; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
  
    int getMaxArea(vector<int> &arr , int n) {
        // int n = arr.size();

        vector<int> next(n);
        next = nextsmallerel(arr,n);

        vector<int> prev(n);
        prev = prevsmallerel(arr,n);

        int area = -1;
        for(int i = 0 ; i < n ; i++){
            int l = arr[i];

            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newarea = l*b;

            area = max(area,newarea);
        }

        return area;
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
        int area = getMaxArea(mat[0],mat[0].size());
        
        for(int i = 1 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                
                if(mat[i][j] != 0){
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                }
                else{
                    mat[i][j] = 0;
                }
            }
            area = max(area , getMaxArea(mat[i],mat[i].size()));
        }
        
        return area;
    }
};