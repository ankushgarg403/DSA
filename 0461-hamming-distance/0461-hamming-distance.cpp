class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = x^y;
        int count = 0;
        while(ans != 0){
            int digit = ans & 1;
            if(digit == 1){
                count++;
            }
            ans = ans >> 1;
        }

        return count;
    }
};