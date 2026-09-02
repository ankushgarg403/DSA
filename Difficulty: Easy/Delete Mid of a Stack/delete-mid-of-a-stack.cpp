class Solution {
  private:
    void solve(stack<int>& s, int N , int count){
        if(count == N/2){
            s.pop();
            return;
        }
        int num = s.top();
        s.pop();

        solve(s,N,count+1);

        s.push(num);
    }
  public:
    void deleteMid(stack<int>& s) {
        int count = 0;
        int N = s.size();
        
        solve(s , N , count);
    }
};