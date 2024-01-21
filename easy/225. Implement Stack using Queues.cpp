//https://leetcode.com/problems/implement-stack-using-queues/description/
//Time: O(n)
//Space: O(n)
class MyStack {
    queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        if (!q1.empty()) {
            int value = q1.front();
            q1.pop();
            return value;
        }
        else {
            int value = q2.front();
            q2.pop();
            return value;
        }
    }
    
    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        else {
            return q2.front();
        }
    }
    
    bool empty() {
        if (!q1.empty())
            return q1.empty() == 1;
        else
            return q2.empty() == 1;
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