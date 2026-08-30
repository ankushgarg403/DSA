/*
Flatten A Linked List

You are given a linked list containing 'n' 'head' nodes, where every node in the linked list contains two pointers:

(1) ‘next’ which points to the next node in the list

(2) ‘child’ pointer to a linked list where the current node is the head.

Each of these child linked lists is in sorted order and connected by 'child' pointer.

Your task is to flatten this linked such that all nodes appear in a single layer or level in a  'sorted order'.

Example:

Input: Given linked list is:

Output:
1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 → 9 → 12 → 20 → null.

Explanation:
The returned linked list should be in a sorted order. All the elements in this returned linked list are connected by 'child' pointers and 'next' pointers point to null.

Input format :

The first line of the input contains a single integer ‘n’ which represents the number of head nodes in the linked list.

The next '2n' lines represent 'n' linked lists connected by next pointer at the head. Description of each of these linked lists is as follows:

The first line contains a single integer 'k', number of nodes in the current linked list.

The next line contains 'k' spaced integers, representing elements of the linked list.

Output format :

Return the head node of the final linked list.

Note:

You don’t have to print anything, it has already been taken care of. Just implement the given function. The flattened list will be printed using the child pointer.

Sample Input 1 :

4
3
1 2 3
3
8 10 15
2
18 22
1
29

Sample Output 1 :

1 2 3 8 10 15 18 22 29

Explanation For Sample Input 1:

The given linked list is 

    

Therefore after flattening the list will become-
1 -> 2 -> 3 -> 8 -> 10 -> 15 -> 18 -> 22 -> 29 ->null

Sample Input 2 :

5
2
4 6
2
5 71
3
7 8 9
3 
11 12 19
3
14 15 17

Sample Output 2 :

4 5 6 7 8 9 11 12 14 15 17 19 71

Expected Time Complexity:

Try solving this in O(n*n*k), where ‘n’ denotes the number of head nodes and ‘k’ is the average number of child nodes in all 'n' sub-lists.     

Expected Space Complexity:

Try solving this without using any extra space.   

Constraints:

1 <= n <= 100
1 <= k <= 20
1 <= Node.data <= 10^9

Time Limit: 1 sec
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
#include<algorithm>
void insertattail(Node* &head , Node* &tail , int d){
	Node* temp = new Node(d);
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	else{
		tail -> child = temp;
		tail = temp;
	}
}

Node* flattenLinkedList(Node* head) 
{
	Node* temp1 = head;
	Node* temp2 = head;

	vector<int> arr;

	while(temp2 != NULL){
		while(temp1 != NULL){
			arr.push_back(temp1 -> data);
			temp1 = temp1 -> child;
		}

		temp2 = temp2 -> next;
		temp1 = temp2;
	}

	sort(arr.begin() , arr.end());

	Node* head1 = NULL;
	Node* tail1 = NULL;

	for(int i = 0 ; i < arr.size() ; i++){
		insertattail(head1,tail1,arr[i]);
	}

	return head1;



}
