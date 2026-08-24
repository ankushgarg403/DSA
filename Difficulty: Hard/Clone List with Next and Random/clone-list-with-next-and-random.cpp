/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = random = nullptr;
    }
};*/

class Solution {
  private:
    void insertattail(Node* &head , Node* &tail , int d){
        Node* clone = new Node(d);
        if(head == NULL){
            head = clone;
            tail = clone;
            return;
        }
        else{
            tail -> next = clone;
            tail = clone;
        }
    }
  public:
    Node* cloneLinkedList(Node* head) {
        Node* temp = head;
        
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        while(temp != NULL){
            insertattail(clonehead , clonetail , temp -> data);
            temp = temp -> next;
        }
        
        unordered_map<Node*,Node*> m;
        Node* original = head;
        Node* clone = clonehead;
        
        while(original != NULL && clone != NULL){
            m[original] = clone;
            original = original -> next;
            clone = clone -> next;
        }
        
        original = head;
        clone = clonehead;
        
        while(original != NULL ){
            clone -> random = m[original -> random];
            original = original -> next;
            clone = clone -> next;
        }
        
        return clonehead;
    }
};