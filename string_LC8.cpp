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

		//str Ϊ��ʱ
		if (str == "")return 0;
		//str ��Ϊ��
		int length = str.size();
		long long res = 0;
		int i = 0;
		//ȥ��ǰ��Ŀհ��ַ�
		while (i<length&&str[i]==' ') {
			i++;
		}
		//ȫΪ�հ��ַ������ߵ�һ���ǿ��ַ����Ϸ�
		if (length == i||allowed.find(str[i])==allowed.end()) {
			return 0;
		}
		//��һ���ǿ��ַ������
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