class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class myQueue {

    Node* front ;
    Node* rear ;
    int count;
    
  public:
    myQueue() {
        front = rear = NULL;
        count = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newnode = new Node(x);
        if(isEmpty()){
            rear = front = newnode;
            count++;
            return ;
        }

        rear -> next = newnode;
        newnode -> next = NULL;
        rear = newnode;
        count++;
    }

    void dequeue() {
        if(isEmpty()){
            // cout<<"Underflow"<<endl;
            return;
        }
        Node* temp = front;
        front = front -> next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
        count--;
    }

    int getFront() {
        if(isEmpty()){
            // cout<<"Underflow"<<endl;
            return -1;
        }

        return front -> data;
    }

    int size() {
        return count;
    }
};
