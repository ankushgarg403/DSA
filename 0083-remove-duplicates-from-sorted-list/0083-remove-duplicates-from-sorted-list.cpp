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
    ListNode* deleteDuplicates(ListNode* head) {
        // map<int,bool> m;
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* curr = NULL;
        // m[temp -> val] = true;
        while(temp -> next != NULL){
            if(temp -> val == temp -> next -> val){
                curr = temp -> next -> next;
                temp -> next -> next = NULL;
                temp -> next = curr;
            }
            else{
                temp = temp -> next;
                // m[temp -> val] = true;
            }
        }
        return head;
    }
};