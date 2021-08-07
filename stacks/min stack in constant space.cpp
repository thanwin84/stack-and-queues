class MinStack {
private:
    vector<int> stack;
    int minE = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int val) {
        if (stack.size() == 0) {
            minE = val;
            stack.push_back(val);
        }
        else {
            if (val >= minE) {
                stack.push_back(minE);
            }
            else {
                int flag_value = 2 * val - minE;
                stack.push_back(flag_value); // value will be saved as flag value
                minE = val;
            }
        }
    }

    void pop() {
        if (stack.back() >= minE) {
            stack.pop_back();
        }
        //if stack[-1] is less than minE, it means this is flag value
        else {
            minE = 2 * minE - stack.back();
            stack.pop_back();
        }
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minE;
    }
};
