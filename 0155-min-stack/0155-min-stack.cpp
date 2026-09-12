class MinStack {
    long long arr[10000000];
    int size = 10000000;
    int top1 ;
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
            if(value >= mini){
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
        long long x = arr[top1];
        top1--;

        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(top1 == -1){
            return -1;
        }
        long long x = arr[top1];

        if(mini > x) return (int)mini;
        return (int)x;
    }
    
    int getMin() {
        if(top1 == -1){
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top11();
 * int param_4 = obj->getMin();
 */