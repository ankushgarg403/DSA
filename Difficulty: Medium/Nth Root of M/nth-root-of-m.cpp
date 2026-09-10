class Solution {
  private:
    int power(int a , int b){
        int ans = 1;
        for(int i = 0 ; i < b ; i++){
            ans = ans*a;
        }
        
        return ans;
    }
  public:
    int nthRoot(int n, int m) {
        if(m == 0) return 0;
        int s = 1;
        int e = m;
        while(e >= s){
            int mid = s + (e-s)/2;
            if(power(mid,n) == m){
                return mid;
            }
            else if(power(mid,n) > m){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return -1;
    }
};