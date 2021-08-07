class Solution {
public:
    int perform(int operand1, int operand2, string op) {
        if (op== "*") {
            return operand1 * operand2;
        }
        else if (op == "-") {
            return operand1 - operand2;
        }
        else if (op == "+") {
            return operand1 + operand2;
        }
        else {
            return operand1 / operand2;
        }
    }
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "*" or tokens[i] == "/" or tokens[i] == "+" or tokens[i] == "-") {
                int num2 = stack.back();
                stack.pop_back();
                int num1 = stack.back();
                stack.pop_back();
                int output = perform(num1, num2, tokens[i]);
                stack.push_back(output);
            }
            else {
                stack.push_back(stoi(tokens[i]));
            }
        }
        return stack.back();
    }
};
