/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        Node* temp = head;
        string check = "";
        
        while(temp != NULL){
            check.push_back(temp -> data);
            temp = temp -> next;
        }
        
        int len = check.length();
        
        int i = 0;
        int j = len-1;
        while(j > i){
            if(check[i] != check[j]){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
};