class MyCircularQueue {
    int* arr;
    int size;
    int front,rear;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
            // arr[rear] = value;
        }
        else if(front > 0 && rear == size-1){
            rear = 0;
            // arr[rear] = value;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else if(front == size - 1){
            front = 0;
        }
        else{
            front++;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        if(front == -1 && rear == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || (rear == (front - 1 + size)%size)){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */