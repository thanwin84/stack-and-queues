#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
#define mod 1000000007
using namespace std;
class Solution {
public:
	bool is_operand(char c) {
		if (c >= '0' and c <= '9') return true;
		else if (c >= 'a' and c <= 'z') return true;
		else if (c >= 'A' and c <= 'Z') return true;
		return false;
	}
	bool is_operator(char c) {
		if (c == '+' || c == '-' || c == '*' || c == '/'|| c == '^') {
			return true;
		}
		return false;
	}
	bool is_openning(char c) {
		if (c == '(' || c == '{' || c == '[') {
			return true;
		}
		return false;
	}
	bool is_closing(char c) {
		if (c == ')' || c == '}' || c == ']') return true;
		return false;
	}
	bool has_higher_precedence(char stack_top, char eq_op) {
		unordered_map<char, int> table;
		table['-'] = 1;
		table['+'] = 1;
		table['*'] = 2;
		table['/'] = 2;
		table['^'] = 3;
		if ( table.count(stack_top) and table.count(eq_op) and table[stack_top] >= table[eq_op]) {
			return true;
		}
		return false;
	}
	string infix_to_postix(string S) {
		string result;
		vector<int> stack;
		for (int i = 0; i < S.size(); i++) {
			if (is_operand(S[i])) {
				result += S[i];
			}
			else if (is_operator(S[i])) {
        // pop until stack top has higher precedence than S[i]
				while (stack.size() > 0 and has_higher_precedence(stack.back(), S[i]) and !is_openning(S[i])) {
					result += stack.back();
					stack.pop_back();
				}
				stack.push_back(S[i]);
			}
			else if (is_openning(S[i])) {
				stack.push_back(S[i]);
			}
			else if (is_closing(S[i])) {
				while (stack.size() > 0 and !is_openning(stack.back())) {
					result += stack.back();
					stack.pop_back();
				}
				stack.pop_back();
			}
		}
		while (stack.size() > 0) {
			result += stack.back();
			stack.pop_back();
		}
		return result;
	}
};
int main() {
	Solution ob;
	string test = "((A+B)*C-D)*E";
	string result = ob.infix_to_postix(test);
	for (auto i : result) {
		cout << i << " ";
	}
    
	return 0;
}
