/*
Basic Calculator
*/
#include<iostream>
using namespace std;

#include<stack>
#include<string>
#include<vector>
#include<algorithm>
#include<regex>
/*
recursion by a stack
*/
class Solution {
public:
	int calculate(string s) {
		if (s.length() == 0)return 0;
		//char digitChar[] = { '0','1','2','3','4','5','6','7','8','9' };
		//const vector<char> digits(digitChar, digitChar + 10);
		stack<int> stack;
		int res = 0;
		int sign = 1;//1 represent +, -1 represents -

		for (int i = 0; i <s.length(); i++) {
			char temp = s[i];
			//digit
			if (temp <= '0' + 9 && temp >= '0') {
				int cur = temp - '0';
				while (i + 1 < s.length() && s[i + 1] <= '0' + 9 && s[i + 1] >= '0') {
					cur = 10 * cur + s[++i] - '0';
				}
				res += sign * cur;
			}
			else if (temp == '-') {
				sign = -1;
			}
			else if (temp == '+') {
				sign = 1;
			}
			else if (temp == '(') {
				stack.push(res);
				res = 0;
				stack.push(sign);
				sign = 1;
			}
			else if (temp == ')') {
				int top1 = stack.top();
				stack.pop();
				res = top1 * res + stack.top();
				stack.pop();
				sign = 1;
			}
		}
		return res;
	}
};

/*
no stack, but still recursion by two variable, val&&num.
*/
class Solution {
private:
	static int eval(string s, int& pos) {
		int val = 0, i = pos, sign = 1, num = 0;
		while (i < s.length()) {
			char c = s[i];
			switch (c) {
			case '+':
				val += sign * num;
				num = 0;
				sign = 1;
				i++;
				break;
			case '-':
				val += sign * num; 
				num = 0;
				sign = -1;
				i++;
				break;
			case '(':
				pos = i + 1;
				val = val += sign * eval(s, pos);
				i = pos;
				break;
			case ')':
				pos = i + 1;
				return val + sign * num;
			case ' ':
				i++;
				continue;
			default:
				num = num * 10 + c - '0';
				i++;
			}
		}
		return val;
	}
public:
	int calculate(string s) {
		if (s.length() == 0) return 0;
		s = "(" + s + ")";
		int pos = 0;
		return eval(s, pos);
	}
};