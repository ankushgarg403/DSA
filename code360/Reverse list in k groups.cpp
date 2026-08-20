/*
Reverse List In K Groups

You are given a linked list of 'n' nodes and an integer 'k', where 'k' is less than or equal to 'n'.

Your task is to reverse the order of each group of 'k' consecutive nodes, if 'n' is not divisible by 'k', then the last group of nodes should remain unchanged.

For example, if the linked list is 1->2->3->4->5, and 'k' is 3, we have to reverse the first three elements, and leave the last two elements unchanged. Thus, the final linked list being 3->2->1->4->5.

Implement a function that performs this reversal, and returns the head of the modified linked list.

Example:

Input: 'list' = [1, 2, 3, 4], 'k' = 2

Output: 2 1 4 3

Explanation:
We have to reverse the given list 'k' at a time, which is 2 in this case. So we reverse the first 2 elements then the next 2 elements, giving us 2->1->4->3.

Note:

All the node values will be distinct.

        

Input Format:

The first line of the input contains a single integer 'n', denoting the number of nodes in the linked list.

The second line contains 'n' space-separated integers, denoting the elements of the linked list.

The third line of input contains an integer 'k'.

Output Format:

Return the head of the modified linked list.

Note:

You don't need to print anything, just implement the given function. Contents of your returned linked list will be printed in a single line.

Sample Input 1:

6
5 4 3 7 9 2
4 

Sample Output 1:

7 3 4 5 9 2

Explanation of the Sample Input 1:

For the given test case, we reverse the nodes in groups of four. But for the last 2 elements, we cannot form a group of four, so leave them as they are. The linked list becomes 7->3->4->5->9->2. Hence the output is 7 3 4 5 9 2

Sample Input 2:

4
4 3 2 8
4 

Sample Output 2:

8 2 3 4

Expected Time Complexity:

Try to solve this in O(n). 

Expected Space Complexity:

Try to solve this using O(1) extra space.    

Constraints:

1 <= n <= 10^4
1 <= k <= n

Time Limit: 1 sec
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */
Node* reverse(Node* head , int k){
    // Base case

    if(head == NULL){
        return NULL;
    }
    
    Node* temp = head;
    int count = 0;

    while(temp != NULL && k > count){
        temp = temp -> next;
        count++;
    }

    if(k > count){
        return head;
    }
    
    // int length = getlen(head);

    // Step 1 : Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int cnt = 0;
    while(curr != NULL && cnt < k){

        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
        cnt++;
    }

    // cnt = length - cnt ;

    // Step 2 : Recursion 
    if(next != NULL && cnt >= k){
        head -> next = reverse(next,k);
    }

    // Step 3 : Return
    return prev;
}

Node* kReverse(Node* head, int k) {
    return reverse(head,k);
}