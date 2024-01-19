//https://leetcode.com/submissions/detail/1150282830/
//Time: O(1)
//Space: O(n)
class MinStack {
public:
    vector<pair<int, int> > values;
    MinStack() {
        
    }
    
    void push(int val) {
        int miValue = 0;
        if (int(values.size())) {
            miValue = min(val, values.back().second);
        }
        else {
            miValue = val;
        }
        values.push_back({val, miValue});
    }
    
    void pop() {
        values.pop_back();
    }
    
    int top() {
        return values.back().first;
    }
    
    int getMin() {
        return values.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */