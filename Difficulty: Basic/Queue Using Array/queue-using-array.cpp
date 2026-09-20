class myQueue {
    
    
  public:
    int size;
    int* arr;
    int front,rear;
    myQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = 0;
    }

    bool isEmpty() {
        if(front == rear){
            return true;
        }
        return false;
    }

    bool isFull() {
        if(rear == size && front == 0){
            return true;
        }
        return false;
    }

    void enqueue(int x) {
        if(rear == size ){
            return;
        }
        
        arr[rear] = x;
        rear++;
    }

    void dequeue() {
        if(isEmpty()){
            return;
        }
        arr[front] = -1;
        front++;
        if(front == rear){
            front = 0;
            rear = 0;
        }
    }

    int getFront() {
        if(isEmpty()) return -1;
        
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        
        return arr[rear-1];
    }
};