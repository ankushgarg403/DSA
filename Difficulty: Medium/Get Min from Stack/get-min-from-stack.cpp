class SpecialStack {
    long long arr[1000];
    int size = 1000;
    int top ;
    long long mini;
  public:
    SpecialStack() {
        top = -1;
        mini = INT_MAX;
    }

    void push(int x) {
        if(top == -1){
            mini = x;
            top++;
            arr[top] = x;
        }
        else{
            if(x > mini){
                top++;
                arr[top] = x;
            }
            else{
                top++;
                arr[top] = 2ll*x - mini;
                mini = x;
            }
        }
    }

    void pop() {
        if(top == -1){
            return;
        }
        int val = arr[top];
        top--;
        
        if(val < mini){
            mini = 2*mini - val;
        }
    }

    int peek() {
        if(top == -1){
            return -1;
        }
        
        int val = arr[top];
        if(mini < val) return val;
        
        return mini;
    }

    bool isEmpty() {
        if(top == -1){
            return true;
        }
        return false;
    }

    int getMin() {
        if(top == -1){
            return -1;
        }
        return mini;
    }
};