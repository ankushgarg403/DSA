/*
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
    Node* reverse(Node* &head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void insertattail(Node* &head , Node* &tail , int d){
        Node* temp = new Node(d);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }

    }
    Node* add(Node* head1, Node* head2){
        int carry = 0;

        Node* anshead = NULL;
        Node* anstail = NULL;
        while(head1 != NULL || head2 != NULL || carry != 0){
            int val1 = 0;
            if(head1 != NULL){
                val1 = head1 -> data;
            }
            int val2 = 0;
            if(head2 != NULL){
                val2 = head2 -> data;
            }

            int sum = carry + val1 + val2;
            int digit = sum%10;

            insertattail(anshead,anstail,digit);

            carry = sum/10;
            if(head1 != NULL){
                head1 = head1 -> next;
            }
            if(head2 != NULL){
                head2 = head2 -> next;
            }
        }
        return anshead;
    }
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        if(head1 -> data == 0 && head2 -> data == 0 && head1 -> next == NULL && head2 -> next == NULL){
            return head1;
        }
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* ans = add(head1,head2);

        ans = reverse(ans);
        
        Node* temp = ans;
        while(temp -> data == 0 && temp != NULL){
            Node* curr = temp -> next;
            temp -> next = NULL;
            temp = curr;
        }
        return temp;
    }
};