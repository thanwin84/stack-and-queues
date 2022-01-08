// keep adding numbers to sum until we see a '('
// if we see '(', push current sum  and sign to the stack so that we can construct new sum
// if we see operator, multiply num with previous sign and set current operator to sum
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
                //setting num = 0 so that we construct new number
                num = 0;
            }
            else if (s[i] == '+') {
                num *= sign;
                sum += num;
                // reset
                sign = 1
                num = 0;
            }
            else if (s[i] == '(') {
                //pushing sum and sign into stack so that we can use later
                stack.push_back(sum);
                stack.push_back(sign);
                // resetting sum = 0 so that we construct new sum for upcoming brackter
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
