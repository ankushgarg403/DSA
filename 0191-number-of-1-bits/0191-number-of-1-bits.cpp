class Solution {
public:
    int hammingWeight(int n) {
        int counter = 0;
        while(n!=0){
            int digit = n&1;
            if (digit==1){
                counter++;
            }
            n = n>>1;
        }
        return counter;
    }
};