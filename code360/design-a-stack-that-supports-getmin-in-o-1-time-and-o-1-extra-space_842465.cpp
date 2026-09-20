/*
Design a stack that supports getMin() in O(1) time and O(1) extra space

Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

Implement the following public functions :

1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and returns nothing.

3. top() :
It returns the element being kept at the top of the stack.

4.  getMin() :
It returns the smallest element present in the stack.

Operations Performed on the Stack:

Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)

Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function)

Input Format:

The first line contains an integer 'Q’, which denotes the number of queries to be run against each operation in the stack. 

The next 'Q' lines represent an operation that needs to be performed.

For the push operation, the input line will contain two integers separated by a single space, representing the type of the operation in the integer and the integer data being pushed into the stack.

For the rest of the operations on the stack, the input line will contain only one integer value, representing the query being performed on the stack.

Output Format:

For Query-1, you do not need to return anything.

For Query-2, you do not need to return anything.

For Query-3, print the data kept on the top of the stack.

For Query-4, print the smallest element present in the stack.

Output for every query will be printed in a separate line.

Note:

You are not required to print anything explicitly. It has already been taken care of. Just implement the function.

Sample Input 1:

6
1 13
1 47
3
1 8
2
4

Sample Output 1:

47
13

Explanation of Input 1:

Here we have six queries in total.

Query 1: Integer 1 represents the push function. Hence we push element ‘13’ onto the stack.

Query 2: Integer 1 represents the push function. Hence we push element ‘47’ onto the stack.

Query 3: Integer 3 represents the top function. Hence we print the top element in stack i.e. '47'.

Query 4: Integer 1 represents the push function. Hence we push element ‘8’ onto the stack.

Query 5: Integer 2 represents the pop function. The stack contains element ‘8’ at the top. We remove/pop ‘8’ from the stack and we have 13, 47 left in stack.

Query 6: Integer 4 represents the getMin function. Hence the min of current stack is '13'.

Sample Input 2:

8
1 45
2
1 53
4
1 46
4
2
4

Sample Output 2:

53
46
53

Constraints:

1 <= 'Q' <= 1000
1 <= query type <= 4
-10^9 <= data <= 10^9 and data != -1

where 'Q' is the total number of queries being performed on the stack and 'data' represents the integer pushed into the stack.

Operations like pop, top and getMin  will always be called on non-empty stacks.

Time Limit: 1 sec
*/

#include<stack>
class SpecialStack {
    stack<int> st;
    int mini;
    public:
        
    void push(int data) {
        if(st.empty()){
            st.push(data);
            mini = data;
        }
        else{
            if(data < mini){
                int val = 2*data - mini;
                st.push(val);
                mini = data;
            }
            else{
                st.push(data);
            }
        }
    }

    void pop() {
        if(st.empty()) return;

        int curr = st.top();
        st.pop();
        if(curr < mini){
            mini = 2*mini - curr;
        }
        // else{
        //     st.pop();
        // }
    }

    int top() {
        if(st.empty()) return -1;
        int curr = st.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        if(st.empty()) return -1;

        return mini;
    }  
};