class kQueues {
  private:
    int k;
    int n;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freespot;
  public:
    kQueues(int n, int k) {
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0 ; i < k ; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        
        next = new int[n];
        
        freespot = 0;
        
        for(int i = 0 ; i < n-1 ; i++){
            next[i] = i+1;
        }
        
        next[n-1] = -1;
        arr = new int[n];
    }

    void enqueue(int x, int i) {
        if(isFull()) return;
        
        int index = freespot;
        
        freespot = next[index];
        
        if(front[i] == -1){
            front[i] = index;
        }
        else{
            next[rear[i]] = index;
        }
        
        rear[i] = index;
        
        arr[index] = x;
        
        next[index] = -1;
    }

    int dequeue(int i) {
        if(front[i] == -1) return -1;
        
        int index = front[i];
        
        front[i] = next[index];
        
        if(front[i] == -1) rear[i] = -1;
        
        next[index] = freespot;
        freespot = index;
        
        return arr[index];
        
    }

    bool isEmpty(int i) {
        if(front[i] == -1) return true;
        return false;
    }

    bool isFull() {
        if(freespot == -1) return true;
        return false;
    }
};