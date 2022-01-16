queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    vector<int> stack;
    queue<int> result;
    int count = 0;
    while (count < k) {
        stack.push_back(q.front());
        count++;
        q.pop();
    }
    while (stack.size() > 0) {
        result.push(stack.back());
        stack.pop_back();
    }
    while (q.size() > 0){
        result.push(q.front());
        q.pop();
    }
    return result;
}
