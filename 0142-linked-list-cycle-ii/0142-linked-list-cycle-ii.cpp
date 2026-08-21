/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,bool> m;
        
        // if(head == NULL || head -> next == NULL){
        //     return NULL;
        // }

        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> next == NULL){
                return NULL;
            }
            if(m[temp]){
                return temp;
            }
            m[temp] = true;
            temp = temp -> next;
        }
        return temp;;

    }
};