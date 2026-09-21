/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* reverse(ListNode* head){
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* temp = reverse(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return temp;
    }

    ListNode* insert(ListNode* &head , int value){
        ListNode* temp = new ListNode(value);
        temp -> next = head;
        head = temp;
        return temp;

    }


public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = NULL;

        int carry = 0;
        while(temp1 != NULL && temp2 != NULL){
            if((temp1 -> val + temp2 -> val + carry) >= 10){
                int sum = temp1 -> val + temp2 -> val + carry;
                int digit = sum%10;
                ans = insert(ans,digit);
                carry = 1;
            }
            else{
                int sum = temp1 -> val + temp2 -> val + carry;
                ans = insert(ans,sum);
                carry = 0;
            }
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        while(temp1 != NULL){
            if((temp1 -> val + carry) >= 10){
                int sum = temp1 -> val + carry;
                int digit = sum%10;
                ans = insert(ans,digit);
                carry = 1;
            }
            else{
                int sum = temp1 -> val + carry;
                ans = insert(ans,sum);
                carry = 0;
            }
            temp1 = temp1 -> next;
        }
        while(temp2 != NULL){
            if((temp2 -> val + carry) >= 10){
                int sum = temp2 -> val + carry;
                int digit = sum%10;
                ans = insert(ans,digit);
                carry = 1;
            }
            else{
                int sum = temp2 -> val + carry;
                ans = insert(ans,sum);
                carry = 0;
            }
            temp2 = temp2 -> next;
        }

        if(carry == 1){
            ans = insert(ans,1);
        }

        return ans;
    }
};