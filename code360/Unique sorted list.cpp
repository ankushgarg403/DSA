/*
Remove duplicates from a sorted Doubly Linked List

A doubly-linked list is a data structure that consists of sequentially linked nodes, and the nodes have reference to both the previous and the next nodes in the sequence of nodes.

You are given a sorted doubly linked list of size 'n'.

Remove all the duplicate nodes present in the linked list.

Example :

Input: Linked List: 1 <-> 2 <-> 2 <-> 2 <-> 3

Output: Modified Linked List: 1 <-> 2 <-> 3

Explanation: We will delete the duplicate values ‘2’ present in the linked list.

Input Format :

The first line contains an integer 'n', the number of elements in the linked list.
The second line contains 'n' integers, the elements of the linked list separated by a single space.

Output Format :

Print a single line, the final linked list.

Note :

You are not required to print anything; it has already been taken care of. Just implement the function.

Sample Input 1 :

5
1 2 2 2 3

Sample Output 1 :

1 2 3

Explanation For Sample Input 1 :

We will delete the duplicate values ‘2’ present in the linked list.

Sample Input 2 :

4
1 2 3 4

Sample Output 2 :

1 2 3 4

Explanation For Sample Input 2 :

The list contains no duplicates, so the final list is unchanged.

Expected time complexity :

The expected time complexity is O('n').

Constraints :

1 <= 'n' <= 10^5
1 <= 'data' in any node <= 10^6

Time limit: 1 sec
*/

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

#include<map>
Node * removeDuplicates(Node *head)
{
    map<int,bool> m;
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* temp = head;
    Node* curr = NULL;

    m[temp -> data] = true;
    while(temp -> next != NULL){
        if(m[temp -> next -> data]){
            curr = temp -> next -> next;
            temp -> next -> next = NULL;
            temp -> next = curr;
        }
        else{
            temp = temp -> next;
            m[temp -> data] = true;
        }
    }
    return head;

}
