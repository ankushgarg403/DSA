class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, pow = 1, sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d;
            if (d > 0) {
                x = d * pow + x;
                pow *= 10;
            }
            n /= 10;
        }
        return x * sum;
    }
};