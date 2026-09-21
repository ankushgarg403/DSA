class Solution {
  private:
    void solve(queue<int> &q , int k , int count , int n){
        if(count == n - k + 1) return;
        
        int el = q.front();
        q.pop();
        solve(q,k,count+1,n);
        
        q.push(el);
    }
    void reverse(queue<int> &q, int k){
        if(q.size() <= 0) return;
        
        int el = q.front();
        q.pop();
        reverse(q,k);
        
        q.push(el);
    }
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        int n = q.size();
        if(n < k){
            return q;
        }
        if(n == k){
            reverse(q,k);
            return q;
        }
        
        if(k > 0){
            reverse(q,k);
            solve(q,k,1,n);
        }
        return q;
    }
};