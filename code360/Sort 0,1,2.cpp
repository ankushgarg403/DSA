/*
Sort 0 1 2

You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s. Write a solution to sort this array/list.

Note :

Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just once.

Input format :

The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case contains an Integer 'N' denoting the size of the array/list.

The second line of each test case contains 'N' space-separated Integers denoting the array/list.

Output format :

For each test case/query, print the sorted array/list(ARR) as space-separated Integers.

Output for every test case will be printed in a separate line.

Note:

You need to change in the given array/list itself. Hence, no need to return or print anything.

Constraints :

1 <= T <= 10
1 <= N <= (5 * (10 ^ 5))
0 <= ARR[i] <= 2

Where 'N' is the size of the given array/list.
And, ARR[i] denotes the i-th element in the array/list.

Time Limit: 1sec 

Sample Input 1 :

2
6
0 1 2 2 1 0
7
0 1 2 1 2 1 2

Sample Output 1 :

0 0 1 1 2 2
0 1 1 1 2 2 2

Sample Input 2 :

2
7
2 2 2 1 1 1 0
6
2 1 2 0 1 0

Sample Output 2 :

0 1 1 1 2 2 2
0 0 1 1 2 2
*/

#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int zero[n];
   int one[n];
   int two[n];
   for(int i=0;i<n;i++){
      zero[i]=-1;
      one[i]=-1;
      two[i]=-1;
   }

   int j = 0;
   int k = 0;
   int l = 0;
   for(int i=0;i<n;i++){
      if(arr[i]==0){
         zero[j]=arr[i];
         j++;
      }
      else if(arr[i]==1){
         one[k]=arr[i];
         k++;
      }
      else{
         two[l]=arr[i];
         l++;
      }
   } 
   j=0;
   k=0;
   l=0;
   for(int i=0;i<n;i++){
      if(zero[j]!=-1){
         arr[i]=zero[j];
         j++;
      }
      else if(one[k]!=-1){
         arr[i]=one[k];
         k++;
      }
      else{
         arr[i]=two[l];
         l++;
      }
   }



}
  


































  
  process.stdin.resume();
  process.stdin.setEncoding('ascii');
  
  var input_stdin = "";
  var input_stdin_array = "";
  var input_currentline = 0;
  
  process.stdin.on('data', function (data) {
  input_stdin += data;
  });
  
  process.stdin.on('end', function () {
  input_stdin_array = input_stdin.split("\n");
  main();    
  });
  
  function readLine() {
  return input_stdin_array[input_currentline++];
  }
  
  
  function main() {
      let t = parseInt(readLine());
      
      while(t-->0){
           let n = parseInt(readLine());
      const arr = readLine().replace(/\s+$/g, '').split(' ');
      
      let array = [];
      
      for(let i = 0 ; i<n ; i++){
          array.push((Number)(arr[i]));
      }
      
      let res = sort(array);
      console.log(...array);
      }
     
  
  }