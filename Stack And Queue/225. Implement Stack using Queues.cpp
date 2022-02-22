class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.size() == 0){
            return -1;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.size() == 0){
            return -1;
        }
        
        return q.front();
    }
    
    bool empty() {
        return (q.size() == 0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
