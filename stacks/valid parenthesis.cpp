lass Solution {
public:
    bool isPair(char openning, char closing) {
        if (openning == '(' and closing == ')') {
            return true;
        }
        else if (openning == '{' and closing == '}') {
            return true;
        }
        else if (openning == '[' and closing == ']') {
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, int> openning;
        unordered_map<char, int> closing;
        openning['('] = 0;
        openning['['] = 0;
        openning['{'] = 0;
        closing[')'] = 0;
        closing['}'] = 0;
        closing[']'] = 0;
        for (int i = 0; i < s.size(); i++) {
            // if we get openning bracket, push it to stack
            if (openning.count(s[i])) {
                stack.push_back(s[i]);
            }
            else {
                // if it is closing pair and stack top is openning pair, 
                //we get a matching pair, we now pop from stack
                if (stack.size() > 0 and isPair(stack.back(), s[i])) {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        // if stack is not empty, it means there are still openning tag which didnt get matching pair
        if (stack.size() == 0) {
            return true;
        }
        //it stack is empty, all got matching brakcet
        return false;
    }
};
