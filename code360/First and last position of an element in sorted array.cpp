/*
First and Last Position of an Element In Sorted Array

You have been given a sorted array/list 'arr' consisting of ‘n’ elements. You are also given an integer ‘k’.

Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

Note :

1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.

Example:

Input: 'arr' = [0,1,1,5] , 'k' = 1

Output: 1 2

Explanation:
If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

Input Format

The first line of each test case contains two single-space separated integers ‘n’ and ‘k’, respectively.

The second line of each test case contains ‘n’ single space-separated integers denoting the elements of the array/list 'arr'.

Output Format :

Return two single-space separated integers denoting the first and the last occurrence of ‘k’ in 'arr', respectively.

Note:

You do not need to print anything; it has already been taken care of. Just implement the given function.

Sample Input 1:

8 2
0 0 1 1 2 2 2 2

Sample output 1:

4 7

Explanation of Sample output 1:

For this testcase the first occurrence of 2 in at index 4 and last occurrence is at index 7.

Sample Input 2:

4 2
1 3 3 5

Sample output 2:

-1 -1

Expected Time Complexity:

Try to do this in O(log(n)).

Constraints:

1 <= n <= 10^5
0 <= k <= 10^9
0 <= arr[i] <= 10^9

Time Limit : 1 second
*/

#include <bits/stdc++.h> 

int firstoccurance(vector<int>& arr, int n, int k , int s , int e){
    int ans = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] == k){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > k){
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}
int lastoccurance(vector<int>& arr, int n, int k , int s , int e){
    int ans = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(arr[mid] == k){
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > k){
            e = mid - 1;
        }
        else{
            s = mid+1;
        }
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;

    p.first = firstoccurance(arr,n,k,0,n-1);
    p.second = lastoccurance(arr,n,k,0,n-1);
    return p;
}