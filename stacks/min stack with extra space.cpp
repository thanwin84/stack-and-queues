class MinStack {
private:
    vector<int> stack;
    vector<int> supporting_stack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        stack.push_back(val);
        if (supporting_stack.size() == 0) {
            supporting_stack.push_back(val);
        }
        else {
            if (supporting_stack.back() >= val) {
                supporting_stack.push_back(val);
            }
        }
    }

    void pop() {
        if (stack.back() == supporting_stack.back()) {
            stack.pop_back();
            supporting_stack.pop_back();
        }
        else {
            stack.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return supporting_stack.back();
    }
};
