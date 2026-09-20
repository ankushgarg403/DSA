class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        if(q.empty()) return;
        
        int el = q.front();
        q.pop();
        
        reverseQueue(q);
        
        q.push(el);
    }
};