/**
 * Definition for singly-linked list.
 * struct ListListNode {
 *     int val;
 *     ListListNode *next;
 *     ListListNode() : val(0), next(nullptr) {}
 *     ListListNode(int x) : val(x), next(nullptr) {}
 *     ListListNode(int x, ListListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* getmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev  = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head -> next == NULL){
            return true;
        }
        
        // Step-1 -> find middle
        ListNode* middle = getmiddle(head);
        
        // Step-2 -> reverse after middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
        // Step-3 -> compare both halfs
        ListNode* head1 = head;
        ListNode* head2 = middle -> next;
        
        while(head2 != NULL){
            if(head1 -> val != head2 -> val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
        // Step-4 -> repeat step 2
        temp = middle -> next;
        middle -> next = reverse(temp);
        
        
        return true;
    }
};