//push: O(1) ans pop: Amortized O(1)
class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> stack1;
    vector<int> stack2;
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // if stack2 is empty, push all elements of stack1 to stack2
        //Hence elements will be stored in reversed order
        // the top element of stack2 is front element of queue
        int item;
        if (stack2.size() == 0) {
            while (stack1.size() > 0) {
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
            item = stack2.back();
            stack2.pop_back();
        }
        else {
            item = stack2.back();
            stack2.pop_back();
        }
        return item;
    }

    /** Get the front element. */
    int peek() {
        int item;
        if (stack2.size() == 0) {
            while (stack1.size() > 0) {
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
            item = stack2.back();
            
        }
        item = stack2.back();
        return item;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.size() == 0 and stack2.size() == 0;
    }
};
