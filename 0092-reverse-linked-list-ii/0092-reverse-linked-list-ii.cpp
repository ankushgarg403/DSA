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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right) return head;


        ListNode* temp = head;
        for(int i = 1 ; i < left-1 ; i++){
            temp = temp -> next;
        }
        if (left == 1) {
            temp = nullptr;
        } else {
            temp = temp;
        }

        // First node of the section
        ListNode* ans = (left == 1) ? head : temp->next;
        ListNode* prev = NULL;
        ListNode* curr = ans;
        ListNode* nxt;

        for(int i = left ; i <= right ; i++){
            nxt = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = nxt;
        }
        if (temp != nullptr)
            temp->next = prev;
        else
            head = prev;
        // temp -> next = prev;
        ans -> next = curr;

        return head;



    }
};