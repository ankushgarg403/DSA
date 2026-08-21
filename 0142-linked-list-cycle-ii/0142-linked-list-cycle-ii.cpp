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
        
        if(head == NULL || head -> next == NULL){
            return NULL;
        }

        ListNode* i = 0;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> next == NULL){
                return NULL;
            }
            if(m[temp]){
                i = temp;
                break;
            }
            m[temp] = true;
            temp = temp -> next;
        }

        ListNode* pos = head;
        // for(int j = 0 ; j <= 10000 ; j++){
        //     if(pos == i){
        //         return pos;
        //     }
        //     pos = pos -> next;
        // }

        while(pos != i){
            pos = pos -> next;
        }
        return pos;

    }
};