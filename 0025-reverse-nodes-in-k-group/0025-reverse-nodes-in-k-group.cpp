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
    ListNode* reverse(ListNode* head , int k){
    // Base case

        if(head == NULL){
            return NULL;
        }
        
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL && k > count){
            temp = temp -> next;
            count++;
        }

        if(k > count){
            return head;
        }
        
        // int length = getlen(head);

        // Step 1 : Reverse first k nodes
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        int cnt = 0;
        while(curr != NULL && cnt < k){

            next = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next;
            cnt++;
        }

        // cnt = length - cnt ;

        // Step 2 : Recursion 
        if(next != NULL && cnt >= k){
            head -> next = reverse(next,k);
        }

        // Step 3 : Return
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head,k);
    }
};