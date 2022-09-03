class MyStack {
public:
    queue<int>q1;
    queue<int>q2;
    MyStack() {
        q1.push(-1);
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int>temp;
        temp=q1;
        q1=q2;
        q2=temp;
    }
    
    int pop() {
        if(q1.front()==-1)return -1;
        else{
            int value=q1.front();
            q1.pop();
            return value;
        }
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.front()==-1)return true;
        else return false;
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
