/*
Square Root of a number

You are given a positive integer ‘n’.

Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

Example:

Input: ‘n’ = 7

Output: 2

Explanation:
The square root of the number 7 lies between 2 and 3, so the floor value is 2.

Input Format:

The first line of input contains the Integer ‘n’.

Output Format:

The output contains an integer denoting the square root of ‘n’.

Note:

You do not need to print anything. It has already been taken care of. Just implement the given function.

Sample Input 1:

6

Sample Output 1:

2

Explanation of Sample Input 1:

The square root of the given number 6 lies between 2 and 3, so the floor value is 2.

Sample Input 2:

100

Sample Output 2:

10

Explanation of Sample Output 2:

The square root of the given number 100 is 10.

Expected Time Complexity:

Try solving this in O(log(n)).

Constraints:

0 <= n <= 10 ^ 9

Time Limit: 1 sec.
*/

int solve(int n , int s , int e , int ans){
    long long int mid = s + (e-s)/2;
    if(mid*mid == n){
        return mid;
    }
    if(e < s){
        return ans;
    }
    if(mid*mid > n){
        return solve(n,s,mid-1,ans);
    }
    else if(mid*mid < n){
        ans = mid;
        return solve(n,mid+1,e,ans);
    }
}

int floorSqrt(int n)
{
    // int ans = 0;
    // int count = 1;
    if(n == 0){
        return 0;
    }
    int ans = -1;
    int a = solve(n,0,n,ans);
    return a;
}

