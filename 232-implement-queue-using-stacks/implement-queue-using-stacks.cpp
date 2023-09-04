class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       // s1.push(x);
       //m-2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        // int popped=-1;
        // if(!s2.empty()){
        //     popped=s2.top();
        // }
        // else{
        //     while(!s1.empty()){
        //         s2.push(s1.top());
        //         s1.pop();
        //     }
        //     popped=s2.top();
        // }
        // s2.pop();
        // return popped;

        //m2
        int popp=-1;
        popp=s1.top();
        s1.pop();
        return popp;
    }
    
    int peek() {
        // int front=-1;
        // if(!s2.empty()){
        //     front=s2.top();
        // }
        // else{
        //     while(!s1.empty()){
        //         s2.push(s1.top());
        //         s1.pop();
        //     }
        //     front=s2.top();
        // }
        // // s2.pop();
        // return front;

        //m2
        int front=-1;
        front=s1.top();
        return front;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
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