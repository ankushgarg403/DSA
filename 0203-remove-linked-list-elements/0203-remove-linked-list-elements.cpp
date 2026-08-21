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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head != NULL && head -> val == val){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        if(head == NULL) return head;
        
        ListNode* temp = head;
        while(temp -> next != NULL){
            if(temp -> next -> val == val){
                ListNode* curr = temp -> next -> next;
                temp -> next = curr;
                curr = NULL;
            }
            else{
                temp = temp -> next;
            }
        }
        return head;
    }
};