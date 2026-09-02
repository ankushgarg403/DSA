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
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL){
            return NULL;
        }

        ListNode* fast = head -> next -> next;
        ListNode* slow = head;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast -> next != NULL){
                fast = fast -> next;
            }
        }
        // ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        // temp -> next = NULL;

        return head;

    }
};