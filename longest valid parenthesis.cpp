//the naive approach is to consider every substring which will take O(n^2) and we have to check every substring if it's valid parenthesis or not
// checking validity will take O(n). so overall time complexity will be O(n^3)
// We can try to use stack data structure
//time: O(n) and space: O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        stack.push_back(0);
        int result = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                stack.push_back(0);
            }
            else {
                if (stack.size() > 1){
                    int num = stack.back();
                    stack.pop_back();
                    int val = stack.back();
                    stack.pop_back();
                    val += num + 2;
                    stack.push_back(val);
                    result = max(val, result);
                }
                else {
                    while(stack.size() > 0) stack.pop_back();
                    stack.push_back(0);
                }
            }
        }
        return result;
    }
};
