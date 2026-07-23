class MyQueue {
    private: 
    stack<int>is;
    stack<int>os;

    void transfer(){
        if(os.empty()){
            while(!is.empty()){
            os.push(is.top());
            is.pop();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        is.push(x);
    }
    
    int pop() {
        transfer();
        int val = os.top();
        os.pop();
        return val;
    }
    
    int peek() {
        transfer();
        return os.top();
    }
    
    bool empty() {
        return os.empty() && is.empty();
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