/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  private:
    void insertattail(Node* &head , Node* &tail , int d){
		Node* temp = new Node(d);
		if(head == NULL){
			head = temp;
			tail = temp;
			return;
		}
		else{
			tail -> bottom = temp;
			tail = temp;
		}
	}
  public:
    Node* flatten(Node* head) {
        Node* temp1 = head;
		Node* temp2 = head;

		vector<int> arr;

		while(temp2 != NULL){
			while(temp1 != NULL){
				arr.push_back(temp1 -> data);
				temp1 = temp1 -> bottom;
			}

			temp2 = temp2 -> next;
			temp1 = temp2;
		}

		sort(arr.begin() , arr.end());

		Node* head1 = NULL;
		Node* tail1 = NULL;

		for(int i = 0 ; i < arr.size() ; i++){
			insertattail(head1,tail1,arr[i]);
		}

		return head1;
    }
};