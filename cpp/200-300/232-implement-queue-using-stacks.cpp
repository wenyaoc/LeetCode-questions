class MyQueue {
public:
    vector<int> stack1;
    vector<int> stack2;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stack2.size() > 0) {
            int x = stack2.back();
            stack2.pop_back();
            return x;
        } else {
            while (!stack1.empty()) {
                int x = stack1.back();
                stack1.pop_back();
                stack2.push_back(x);
            }
            int x = stack2.back();
            stack2.pop_back();
            return x;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(stack2.size() > 0){
            return stack2.back();
        } else {
            while(!stack1.empty()){
                int x = stack1.back();
                stack1.pop_back();
                stack2.push_back(x);
            }
            return stack2.back();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack1.empty() && stack2.empty()){
            return true;
        } else {
            return false;
        }
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
