/*
Next Greater Element

You are given an array 'a' of size 'n'.

Print the Next Greater Element(NGE) for every element.

The Next Greater Element for an element 'x' is the first element on the right side of 'x' in the array, which is greater than 'x'.

If no greater elements exist to the right of 'x', consider the next greater element as -1.

For example:

Input: 'a' = [7, 12, 1, 20]

Output: NGE = [12, 20, 20, -1]

Explanation: For the given array,

- The next greater element for 7 is 12.

- The next greater element for 12 is 20. 

- The next greater element for 1 is 20. 

- There is no greater element for 20 on the right side. So we consider NGE as -1.

Input Format:

The first line of input contains an integer 'n' representing the size of the array.

The second line of input contains 'n' single space-separated integers representing the elements of the array.

Output Format :

The only line of output contains 'n' single space-separated integers representing the Next Greater Element for each element. 

Note :

You do not need to print anything; it has already been taken care of. Just implement the given function.

Sample Input 1:

5
1 5 3 4 2

Sample Output 1:

5 -1 4 -1 -1

Sample Input 2:

5
5 5 5 5 5

Sample Output 2:

-1 -1 -1 -1 -1

Expected time complexity :

The expected time complexity is O(n).

Constraints :

1 <= 'n' <= 10^5
1 <= 'a[i]' <= 10^9

Time Limit: 1 sec
*/

#include<stack>
vector<int> nextGreaterElement(vector<int>& arr, int n)
{
	stack<int> st;
	st.push(-1);
	
	// int n = arr.size();
	
	vector<int> ans(n);
	
	int i = n - 1;
	
	while(i >= 0){
		int el = arr[i];
		while(st.top() <= el){
			if(st.top() == -1){
				// ans[i] = -1;
				// st.push(el);
				break;
			}
			st.pop();
		}
		ans[i] = st.top();
		st.push(el);
		i--;
	}
	
	return ans;
}