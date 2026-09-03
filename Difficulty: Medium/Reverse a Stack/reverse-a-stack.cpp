class Solution {
  private:
    void insertatbottom(stack<int> &stack , int x){
        if(stack.empty()){
            stack.push(x);
            return;
        }

        int num = stack.top();
        stack.pop();

        insertatbottom(stack,x);

        stack.push(num);
    }

    void solve(stack<int> &stack){
        if(stack.empty()){
            return;
        }

        int num = stack.top();
        stack.pop();

        solve(stack);

        insertatbottom(stack,num);
    }
  public:
    void reverseStack(stack<int> &st) {
        solve(st);
        return;
    }
};