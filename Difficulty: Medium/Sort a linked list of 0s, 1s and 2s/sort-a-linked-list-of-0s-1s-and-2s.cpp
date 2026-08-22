/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  private:
    void insert(Node* &tail , Node* curr){
        tail -> next = curr;
        tail = curr;
    }
  public:
    Node* segregate(Node* head) {
        Node* zerohead = new Node(-1); // Dummy values are required, otherwise
        Node* zerotail = zerohead; // we need many if else conditions
        Node* onehead = new Node(-1);
        Node* onetail = onehead;
        Node* twohead = new Node(-1);
        Node* twotail = twohead;

        Node* curr = head;

        // Create seperate ll
        while(curr != NULL){
            int value = curr -> data;

            if(value == 0){
                insert(zerotail , curr);
            }
            else if(value == 1){
                insert(onetail , curr);
            }
            else if(value == 2){
                insert(twotail , curr);
            }

            curr = curr -> next;
        }

        // Merging 3 sublists

        // List is non empty
        if(onehead -> next != NULL){
            zerotail -> next = onehead -> next;
        }
        // List is empty 
        else{
            zerotail -> next = twohead -> next;
        }

        onetail -> next = twohead -> next;
        twotail -> next = NULL;

        // Setting heads
        head = zerohead -> next;

        // Deleting 
        delete zerohead;
        delete onehead;
        delete twohead;

        return head;
        
    }
};