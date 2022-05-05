class MyStack {
public:
    queue<int> que1 , que2;
    MyStack() {}
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        while(que1.size() > 1){
            int top = que1.front();
            que2.push(top);
            que1.pop();
        }
        int top = que1.front();
        que1 = que2;
        while(!que2.empty()){
            que2.pop();            
        }
        // que1.pop();
        return top;
    }
    
    int top() {
        while(que1.size() > 1){
            int top = que1.front();
            que2.push(top);
            que1.pop();
        }
        int top = que1.front();
        que1.pop();
        que2.push(top);
        que1 = que2;
        while(!que2.empty()){
            que2.pop();            
        }
        return top;
    }
    
    bool empty() {
        return que1.empty();
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