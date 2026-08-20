/*
Circularly Linked

You are given the head of a linked list containing integers, You need to find out whether the given linked list is circular or not.

Note :

1. A linked list is said to be circular if it has no node having its next pointer equal to NULL and all the nodes form a circle i.e. the next pointer of last node points to the first node.
2. An empty linked will also be considered as circular.
3. All the integers in the linked list are unique.
4. In the input, the next pointer of a node with i’th integer is linked to the node with data (i+1)’th integer (If (i+1)’th node exists). If there is no such (i+1)’th integer then the next pointer of such node is set to NULL.

Input format :

The first line of input contains an integer T, denoting the number of test cases.

The first line of each test case consists of an integer N, denoting the number of links in the linked list. 

The second line of each test case consists of N space-separated integers denoting the data of the linked list and linking between nodes of the linked list as described in the notes above.

For more clarity please refer to the sample input.

Output format :

For each test case, print ‘True’ or ‘False’ depending on whether the linked list is circular or not, in a separate line.

Note :

You don't have to print anything, it has already been taken care of. Just Implement the given function.

Constraints :

1 <= T <= 10 ^ 2
1 <= D <= 10 ^ 6, here D is data stored in the node.
0 <= N <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :

1
5
1 2 3 4 1

Sample Output 1 :

True

Explanation of sample input 1 :

Given Linked list look like following:

As given linked list form a circle, hence it is a Circular linked list.

Sample Input 2 :

1
7
1 2 3 4 5 6 7

Sample Output 2 :

False

Explanation of sample input 2 :

Given Linked list look like following:

In the given linked list there is a node at which this linked list terminates, hence it is not a circular linked list.
*/

#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){

    if(head == NULL) return true;
    if(head -> next == NULL) return false;
    

    Node* slow = head;
    Node* fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast){
            break;
        }
    }

    if(fast == slow && slow == head)return true;
    return false;
}
