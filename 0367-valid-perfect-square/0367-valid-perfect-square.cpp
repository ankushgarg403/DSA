class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return 1;

        int s = 0;
        int e = num/2;

        while(e >= s){
            int mid = s + (e-s)/2;
            if(mid*mid == num){
                return true;
            }
            else if(mid > num/mid){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return false;
    }
};