/*
Check If Binary Representation of a Number is Palindrome

Ninja is given an integer ‘N’. Ninja wants to find whether the binary representation of integer ‘N’ is palindrome or not.

A palindrome is a sequence of characters that reads the same backward as forward.

Ninja is busy with his training. Help Ninja in finding out whether the binary representation of ‘N’ is palindrome or not.

Input format:

The first line contains a single integer ‘T’ representing the number of test cases.

The first and only line of each test case contains a single integer ‘N’ denoting the given integer.

Output format:

 Return true if the binary representation of the given number is a palindrome. Else return false.

Note:

 You do not need to print anything, it has already been taken care of. Just implement the given function.

Constraints:

1 <= ‘T’ <= 100
1 <= ‘N’ <= 10^18

Time Limit :  1 sec

Sample Input 1:

2    
7
10

Sample Output 1:

true
false

Explanation for Sample Output 1:

For the first test case :
The binary representation of 7 is 111. Hence it is a palindrome.

For the second test case:
The binary representation of 10 is 1010. Hence it is not a palindrome.

Sample Input 2:

2    
3
5

Sample Output 2:

true
true
*/

#include <bits/stdc++.h>

bool solve(string& num , int s , int e){
	if(s >= e){
		return true;
	}
	if(num[s] != num[e]){
		return false;
	}
	else{
		return solve(num,s+1,e-1);
	}
}

bool checkPalindrome(long long N)
{
	long long int binary = 0;
	int count = 0;
	string num = "";
	while(N != 0){
		int digit = N % 2;
		N = N/2;
		num = num + char(digit+'0');
	}
	return solve(num,0,num.length()-1);
}