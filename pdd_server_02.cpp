#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<stack>
class  Solution {
public:
	bool matchStr(string s) {
		int len = s.size();
		stack<char> stack;

		/*
		flag used for judge different parentheses
		0: none  1:()  2:[]  3: {}
		*/
		int flag = 0;
		//count the num of paren in the stack.
		int count = 0;
		for (int i = 0; i < len; i++) {
			//more right paren
			if (count <= 0&&( s[i] == ')' || s[i] == ']' || s[i] == '}')) {
				return false;
			}
			if (s[i] == '(') {
				//( can be in none and [
				//ensure the containing order right
				//below if blocks are the same
				if (flag != 2 && flag != 0)return false;
				flag = 1;
				//stack ensure the pair right
				stack.push('(');
				count++;
			}
			if (s[i] == '[') {
				//[ can only be in {}
				if (flag != 3 && flag != 0)return false;
				flag = 2;
				stack.push('[');
				count++;
			}
			if (s[i] == '{') {
				if (flag != 3 && flag != 0)return false;
				flag = 3;
				stack.push('{');
				count++;
			}
			if (s[i] == ')') {
				if (stack.top() != '(')return false;
				stack.pop();
				count--;
				if (count>0 && stack.top() == '[') {
					//( in [
					flag = 2;
				}
				else {
					flag = 0;
				}
			}
			if (s[i] == ']') {
				if (stack.top() != '[')return false;
				stack.pop();
				count--;
				if (count>0 && stack.top() == '{') {
					//[ in {
					flag = 3;
				}
				else {
					flag = 0;
				}
			}
			if (s[i] == '}') {
				if (stack.top() != '{')return false;
				stack.pop();
				count--;
				if (count>0&&stack.top() == '{') {
					//still {
					flag = 3;
				}
				else {
					flag = 0;
				}
			}
		}
	}
};