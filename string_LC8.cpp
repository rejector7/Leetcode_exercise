#include<iostream>
using namespace std;
#include<string>
//#include<stack>
#include<set>
#define INT_MAX 2147483647
#define INT_MIN -2147483647-1
class Solution {
public:
	int myAtoi(string str) {
		//stack<char> reversed;
		
		char allowed_char[] = { '0', '1','2','3','4','5','6','7','8','9','+','-' };
		set<char> allowed(allowed_char, allowed_char + 12);
		set<char> allowed_num(allowed_char, allowed_char + 10);

		//str 为空时
		if (str == "")return 0;
		//str 不为空
		int length = str.size();
		long long res = 0;
		int i = 0;
		//去掉前面的空白字符
		while (i<length&&str[i]==' ') {
			i++;
		}
		//全为空白字符，或者第一个非空字符不合法
		if (length == i||allowed.find(str[i])==allowed.end()) {
			return 0;
		}
		//第一个非空字符的情况
		if (str[i] == '+' || str[i] == '-') {
			//int sign = 1;
			//if (str[i] == '-')sign = -1;
			
			char temp = str[i];
			i++;
			if (allowed_num.find(str[i]) == allowed_num.end()) {
				return 0;
			}
			while (i<length&&allowed_num.find(str[i]) != allowed_num.end()) {
				res = res*10 + str[i] - '0';
				if (res > INT_MAX ) {
					if (temp == '+') {
						return INT_MAX;
					}
					else {
						return INT_MIN;
					}
				}
				i++;
			}
			if (temp == '+') {
				return (int)res;
			}
			else return  - (int)res;
		}
		else {
			while (i<length&&allowed_num.find(str[i]) != allowed_num.end()) {
				res = res * 10 + str[i] - '0';
				if (res >= INT_MAX) {
					return INT_MAX;
				}
				i++;
			}
			return (int)res;
		}
	}
};