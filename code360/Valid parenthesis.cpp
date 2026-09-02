/*
Valid Parentheses

You're given a string 'S' consisting of "{", "}", "(", ")", "[" and  "]" .

Return true if the given string 'S' is balanced, else return false.

For example:

'S' = "{}()".

There is always an opening brace before a closing brace i.e. '{' before '}', '(' before ').
So the 'S' is Balanced.

Input Format:

The first and only input line contains a string 'S'.

Output format :

The only line of output contains 'Balanced' or 'Not Balanced'.

Note:

You are not required to print anything explicitly. It has already been taken care of. Just implement the given function.

Sample Input 1 :

[()]{}{[()()]()}

Sample Output 1 :

Balanced

Explanation Of the Sample Input 1 :

There is always an opening brace before a closing brace i.e. '{' before '}', '(' before '), '[' before ']'.
So the 'S' is Balanced.

Sample Input 2 :

[[}[

Sample Output 2 :

Not Balanced

Constraints:

1 <= 'N' <= 10^5

Where 'N' is the length of the input string 'S'.
Time Limit: 1 sec
*/

bool isValidParenthesis(string s)
{
    stack<char> st;

        for(int i = 0 ; i < s.length() ; i++){
            char ch = s[i];

            if(ch == '[' || ch == '(' || ch == '{'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[')){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;

        return false;
}