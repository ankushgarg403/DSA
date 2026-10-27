class MinStack {
    long long arr[1000000];
    int top1;
    long long mini;
public:
    MinStack() {
        top1 = -1;
        mini = INT_MAX;
    }
    
    void push(int value) {
        if(top1 == -1){
            mini = value;
            top1++;
            arr[top1] = value;
        }
        else{
            if(mini < value){
                top1++;
                arr[top1] = value;
            }
            else{
                top1++;
                arr[top1] = 2LL * value - mini;
                mini = value;
            }
        }
    }
    
    void pop() {
        if(top1 == -1) return;

        long long i = arr[top1];
        top1--;

        if(mini > i){
            mini = 2 * mini - i;
        }
    }
    
    int top() {
        if(top1 == -1) return -1;

        long long i = arr[top1];

        if(i > mini) return (int)i;
        return (int)mini;
    }
    
    int getMin() {
        if(top1 == -1) return -1;

        return mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */