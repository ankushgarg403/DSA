class Solution {
public:
    bool isPowerOfTwo(int n) {
        int m = n;
        long counter = 0;
        if (n>0){
            while (m!=0){
                int bit = m&1;
                if (bit == 1){
                    counter++;
                }
                m = m >> 1;
            }
        }
        if (counter > 1 || n <= 0){
            return false;
        }
        return true;
    }
};