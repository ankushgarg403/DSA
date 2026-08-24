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
        tail -> next = clone;
        tail = clone;
    }
public:
    Node* copyRandomList(Node* head) {
        // Step-1 -> Clone only next pointer
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        Node* temp = head;

        while(temp != NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp -> next;
        }

        // Step-2 -> Create a map
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

        while(original != NULL && clone != NULL){
            clone -> random = m[original -> random];
            original = original -> next;
            clone = clone -> next;
        }

        return clonehead;

    }
};