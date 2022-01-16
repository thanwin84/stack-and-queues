//the naive approach is to consider every substring which will take O(n^2) and we have to check every substring if it's valid parenthesis or not
// checking validity will take O(n). so overall time complexity will be O(n^3)
// We can try to use stack data structure
//time: O(n) and space: O(n)
//using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        vector<int> stack;
        stack.push_back(0);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.push_back(0);
            }
            else {
                if (stack.size() > 1) {
                    //we got a matching pair
                    int num = stack.back();
                    stack.pop_back();
                    //adding current value to previously found matching value
                    int prev_value = num + stack.back() + 2;
                    stack.pop_back();
                    ans = max(ans, prev_value);
                    stack.push_back(prev_value);
                }
                else {
                    while (stack.size() > 0) {
                        stack.pop_back();
                    }
                    stack.push_back(0);
                }
            }
        }
        return ans;
    }
};
//time: O(n) and space: O(n)
// Dynamic approach
// We make use of a dp array where iith element dp[i] represents the length of the longest valid substring ending at iith index
//substring ending with ')' will make matching pair, this leads to conclusion that substring ending with '(' will contain 0 at their correspoding dp indices
class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.size() + 1];
        int best_ans = 0;
        int n = s.size();
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            dp[i] = 0;
            if (s[i] == ')'){
                if (s[i -1] == '('){
                    if (i == 1) dp[i] = 2;
                    else dp[i] = dp[i - 2] + 2;
                }
                else if (s[i -1] == ')'){
                    if (i - dp[i -1] -1 >= 0 and s[i - dp[i -1] -1] == '('){
                        if (i - dp[i -1] - 2 >= 0){
                            dp[i] = dp[i -1] + dp[i - dp[i -1] -2] + 2;
                        }
                        else dp[i] = dp[i -1] + 2;
                    }
                }
            }
            best_ans = max(best_ans, dp[i]);
                }
        return best_ans;
    }
};
