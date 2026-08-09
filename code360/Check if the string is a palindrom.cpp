/*
Check If The String Is A Palindrome

You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

Note :

String 'S' is NOT case sensitive.

Example :

Let S = “c1 O$d@eeD o1c”.
If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “c1odeedo1c”, which is a palindrome. Hence, the given string is also a palindrome.

Input format :

The very first line of input contains an integer 'T' denoting the number of test cases. 

The first line of every test case contains the string 'S'.

Output format :

For each test case, print “Yes” if 'S' is a palindrome, and “No” otherwise.

Print the output of each test case in a separate line.

Note :

You do not need to print anything, it has already been taken care of. Just implement the given function.

Follow Up :

Can you solve the problem using O(1) space complexity?

Constraints :

1 <= T <= 100 
1 <= Length(S) <= 10^4

Where 'T' denotes the number of test cases and 'S' denotes the given string.

Time Limit : 1 sec

Sample Input 1 :

2
N2 i&nJA?a& jnI2n
A1b22Ba

Sample Output 1 :

Yes
No

Explanation 1 :

For the first test case, S = “N2 i&nJA?a& jnI2n”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “n2injaajni2n”, which is a palindrome. Hence, the given string is also a palindrome.

For the second test case, S = “A1b22Ba”. If we ignore the special characters, whitespaces and convert all uppercase letters to lowercase, we get S = “a1b22ba”, which is not a palindrome. Hence, the given string is not a palindrome.

Sample Input 2 :

3
codingninjassajNiNgNidoc
5?36@6?35
aaBBa@

Sample Output 2 :

Yes
Yes
No
*/

#include <bits/stdc++.h> 

char tolowercase(char s){
    if(s >= 'a' && s <= 'z'){
        return s;
    }
    else if(s >= 'A' && s <= 'Z'){
        char temp = s - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string s)
{
    int len = 0;
    for(int i = 0 ; s[i] != '\0' ; i++){
        len++;
    }
    int start = 0;
    int end = len - 1;
    while(start <= end){
        if(!(tolowercase(s[start]) >= 'a' && tolowercase(s[start]) <= 'z')){
            if(!(s[start] >= '0' && s[start] <= '9')){
                // if(s[start] == '\0')
                    start++;
                    continue;
            }
        }
        if(!(tolowercase(s[end]) >= 'a' && tolowercase(s[end]) <= 'z')){
            if(!(s[end] >= '0' && s[end] <= '9')){
                // if(s[end] == '\0')
                    end--;
                    continue;
            }
        }

        if(tolowercase(s[start]) != tolowercase(s[end])){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}