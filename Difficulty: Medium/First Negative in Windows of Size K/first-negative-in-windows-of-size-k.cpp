class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<int> q;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0 ; i < k ; i++){
            if(arr[i] < 0){
                q.push_back(i);
            }
        }
        
        for(int i = k ; i < n ; i++){
            if(!q.empty()){
                ans.push_back(arr[q.front()]);
            }
            else{
                ans.push_back(0);
            }
            
            while(!q.empty() && q.front() <= i-k){
                q.pop_front();
            }
            
            if(arr[i] < 0){
                q.push_back(i);
            }
        }
        
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        return ans;
    }
};