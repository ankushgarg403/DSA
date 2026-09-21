class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char> q;
        vector<int> count(26,0);
        
        string ans = "";
        
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            char el = s[i];
            if(count[el - 'a'] == 0){
                q.push(el);
            }
            count[el-'a']++;
            
            while(!q.empty() && count[q.front() - 'a'] > 1){
                q.pop();
            }
            
            if(!q.empty()){
                ans += q.front();
            }
            else{
                ans += '#';
            }
        }
        
        return ans;
    }
};