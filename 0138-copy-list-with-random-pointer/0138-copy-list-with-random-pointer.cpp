/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

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
    Node* copyRandomList(Node* head) {
        // Step-1 -> Clone the node
        Node* temp = head;

        Node* clonehead = NULL;
        Node* clonetail = NULL;
        while(temp != NULL){
            insertattail(clonehead , clonetail , temp -> val);
            temp = temp -> next;
        }

        // Step-2 -> Add clone node between original nodes
        Node* clone = clonehead;
        Node* original = head;
        while(clone != NULL && original != NULL){
            // For original Nodes
            Node* next = original -> next;
            original -> next = clone;
            original = next;

            // For clone Nodes
            next = clone -> next;
            clone -> next = original;
            clone = next;
        }

        // Step-3 -> Random pointer copy
        temp = head;
        while(temp != NULL){
            if(temp -> next != NULL){
                temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
            }
            temp = temp -> next -> next;
        }

        // Step-4 -> Revert the changes
        original = head;
        clone = clonehead;
        while(clone != NULL && original != NULL){
            original -> next = clone -> next;
            original = original -> next;

            if(original != NULL){
                clone -> next = original -> next;
            }
            clone = clone -> next;
        }

        return clonehead;
    }
};