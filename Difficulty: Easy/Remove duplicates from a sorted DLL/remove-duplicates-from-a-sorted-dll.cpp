/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        map<int,bool> m;
        if(headRef == NULL || headRef -> next == NULL){
            return headRef;
        }
        Node* temp = headRef;
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
        return headRef;
    }
};