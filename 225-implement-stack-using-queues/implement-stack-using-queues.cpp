class MyStack {
public:
// queue<int>q1,q2;
queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        // q2.push(x);
        // while(!q1.empty()){
        //     q2.push(q1.front());
        //     q1.pop();
        // }
        // while(!q2.empty()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }

        //m2
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++){
            int top=q1.front();
            q1.pop();
            q1.push(top);
        }
    }
    
    int pop() {
        // int popp=-1;
        // popp=q1.front();
        // q1.pop();
        // return popp;

        //m2
        int popp=-1;
        popp=q1.front();
        q1.pop();
        return popp;
    }
    
    int top() {
        // int topp=-1;
        // topp=q1.front();
        // return topp;

        //m2
        int topp=-1;
        topp=q1.front();
        return topp;
    }
    
    bool empty() {
        // return q1.empty() && q2.empty();
        return q1.empty();
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