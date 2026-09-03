/*
Reverse Stack Using Recursion

Reverse a given stack of 'N' integers using recursion. You are required to make changes in the input parameter itself.

Note: You are not allowed to use any extra space other than the internal stack space used due to recursion.

Example:

Input: [1,2,3,4,5] 
Output: [5,4,3,2,1]

Input Format :

The first line of input contains an integer value 'N', denoting the size of the input Stack.

The second line contains 'N' single space-separated integers, denoting the stack elements, where the leftmost integer denotes the TOP element of Stack.    

Output Format :

'N' single space-separated integers in a single line, where the leftmost integer denotes the TOP element of the reversed stack.

Sample Input 1 :

3
2 1 3

Sample Output 1 :

3 1 2

Explanation to Sample Input 1 :

Reverse of a give stack is 3 1 2 where first element becomes last and last becomes first.                   

Sample Input 2 :

2
3 2

Sample Output 2 :

2 3

Constraints :

0 <= N <= 10^3
Where 'N' is the number of elements in the given stack.

Time Limit: 1 sec
*/

void insertatbottom(stack<int> &stack , int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertatbottom(stack,x);

    stack.push(num);
}

void solve(stack<int> &stack){
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    solve(stack);

    insertatbottom(stack,num);
}

void reverseStack(stack<int> &stack) {
    solve(stack);
    return;
    
}