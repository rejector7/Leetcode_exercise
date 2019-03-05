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

		//str Ϊ��ʱ
		if (str == "")return 0;
		//str ��Ϊ��
		int length = str.size();
		long long res = 0;
		int i = 0;
		//ȥ��ǰ��Ŀհ��ַ�
		while (i<length&&str[i] == ' ') {
			i++;
		}
		//ȫΪ�հ��ַ������ߵ�һ���ǿ��ַ����Ϸ�
		if (length == i || (str[i] != '+'&&str[i] != '-' && (str[i] < '0' || str[i] > '9'))) {
			return 0;
		}
		//��һ���ǿ��ַ������
		if (str[i] == '+' || str[i] == '-') {
			//int sign = 1;
			//if (str[i] == '-')sign = -1;
			char temp = str[i];
			i++;
			if ((str[i] < '0' || str[i] > '9')) {
				return 0;
			}
			while (i<length&& (str[i] >='0' && str[i] <= '9')) {
				res = res * 10 + str[i] - '0';
				if (res > INT_MAX) {
					switch (temp) {
					case '+': return INT_MAX; break;
					case '- ': return INT_MIN; break;
					default:break;
					}
				}
				i++;
			}
			if (temp == '+') {
				return (int)res;
			}
			else return  -(int)res;
		}
		else {
			while (i<length&& (str[i] >= '0' && str[i] <= '9')) {
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