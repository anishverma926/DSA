class MyQueue {
public:
    stack<int> s;

    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(s.empty())
        return -1;

        int x = s.top();
        s.pop();

        if(s.empty())
        return x;

        int ans = pop();
        s.push(x);

        return ans;
    }
    
    int peek() {
        if(s.empty())
        return -1;

        int x = s.top();
        s.pop();

        if(s.empty()){
            s.push(x);
            return x;
        }
        
        int ans = peek();
        s.push(x);

        return ans;
    }
    
    bool empty() {
       return s.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */