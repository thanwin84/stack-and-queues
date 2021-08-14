class Solution {
public:
    bool is_digit(char c) {
        if (c >= '0' and c <= '9') return true;
        return false;
    }
    int calculate(string s) {
        long long int sum = 0;
        long long int num = 0;
        int sign = 1;
        vector<long long int> stack;
        for (int i = 0; i < s.size(); i++) {
            if (is_digit(s[i])) {
                num = num * 10 + s[i] - '0';
            }
            else if (s[i] == '-') {
                num *= sign;
                sum += num;
                sign = -1;
                num = 0;
            }
            else if (s[i] == '+') {
                num *= sign;
                sum += num;
                sign = 1;
                num = 0;
            }
            else if (s[i] == '(') {
                stack.push_back(sum);
                stack.push_back(sign);
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')') {
                sum += (sign * num);
                sum *= stack.back();
                stack.pop_back();
                sum += stack.back();
                stack.pop_back();
                num = 0;
            }
        }
        sum += sign * num;
        return sum;
    }
};
