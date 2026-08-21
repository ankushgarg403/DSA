/* Structure of linked list Node
class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
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
};