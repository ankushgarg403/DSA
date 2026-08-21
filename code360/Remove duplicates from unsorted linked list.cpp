/*
Remove Duplicates From an Unsorted Linked List

You are given a linked list of N nodes. Your task is to remove the duplicate nodes from the linked list such that every element in the linked list occurs only once i.e. in case an element occurs more than once, only keep its first occurrence in the list.

For example :

Assuming the linked list is 3 -> 2 -> 3 -> 4 -> 2 -> 3 -> NULL.

Number ‘2’ and ‘3’ occurs more than once. Hence we remove the duplicates and keep only their first occurrence. So, our list becomes : 3 -> 2 -> 4 -> NULL.

Input Format :

The first line of input contains an integer ‘T’ representing the number of test cases.

The first and the only line of every test case contains the elements of the linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

Output Format :

For each test case, the resulting linked list is printed.

Note :

When multiple nodes have the same element, the node which appeared first is kept, all other duplicates are removed i.e. the order of the nodes should be preserved.

You don’t need to print anything. It has already been taken care of. Just implement the given function.

Constraints :

1 <= T <= 100   
1 <= N <= 10 ^ 4
1 <= data <= 10 ^ 5 

Where ‘N’ is the number of nodes in the list and 'data' is the value of list nodes.

Time Limit: 1sec

Sample Input 1 :

2
4 2 5 4 2 2 -1
1 2 1 2 2 2 7 7 -1

Sample Output 1 :

4 2 5 -1
1 2 7 -1

Explanation of Sample Input1 :

For the first test case, the linked list is 4 -> 2 -> 5 -> 4 -> 2 -> 2 -> NULL. Number ‘4’ and ‘2’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 4 -> 2 -> 5 -> NULL.

For the second test case, the linked list is 1 -> 2 -> 1 -> 2 -> 2 -> 2 -> 7 -> 7 -> NULL. Number ‘1’, ‘2’ and ‘7’ occurs more than once. Hence, we remove the duplicates and keep only their first occurrence. So, our list becomes : 1 -> 2 -> 7 -> NULL.

Sample Input 2 :

2
3 3 3 3 3 -1
10 20 10 20 30 10 20 30 -1

Sample Output 2 :

3 -1
10 20 30 -1
*/

#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    unordered_map<int,bool> m;

    if(head == NULL || head -> next == NULL){
        return head;
    }

    m[head -> data] = true;

    Node* temp = head;
    while(temp -> next != NULL){
        if(m[temp -> next -> data]){
            Node* curr = temp -> next -> next;
            temp -> next = curr;
            curr = NULL;
        }
        else{
            m[temp -> next -> data] = true;
            temp = temp -> next;
        }
    }
    return head;
}