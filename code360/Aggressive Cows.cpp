/*
Aggressive Cows

You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

You are also given an integer 'k' which denotes the number of aggressive cows.

You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

Print the maximum possible minimum distance.

Example:

Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

Output: 2

Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.

Input format :

The first line contains two integers ‘n’ and ‘k’ denoting the number of elements in the array and the number of aggressive cows.

The second line contains ‘n’ single space-separated integers denoting the position of the stalls.

Output format :

Return the largest possible minimum distance between cows.

Note :

You do not need to print anything; it has already been handled.

Sample Input 1 :

6 4
0 3 4 7 10 9

Sample Output 1 :

3

Explanation to Sample Input 1 :

The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here distance between cows are 3, 4 and 3 respectively.

Sample Input 2 :

5 2
4 2 1 3 6

Sample Output 2 :

5

Expected time complexity:

Can you solve this in O(n * log(n)) time complexity?

Constraints :

2 <= 'n' <= 10 ^ 5
2 <= 'k' <= n
0 <= 'arr[i]' <= 10 ^ 9
Time Limit: 1 sec.
*/

int ispossible(vector<int> &stalls, int k , int mid){
    int cow = 1;
    int lastpos = stalls[0];
    for(int i = 0 ; i < stalls.size() ; i++){
        if(stalls[i] - lastpos >= mid){
            cow++;
            if(cow == k){
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin() , stalls.end());
    int e = stalls[stalls.size()-1];
    int s = 0;
    int ans = -1;
    while(e >= s){
        int mid = s + (e-s)/2;
        if(ispossible(stalls,k,mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}