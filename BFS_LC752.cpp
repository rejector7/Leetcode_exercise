#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<math.h>
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		vector<vector<int>> graph = setGraph(deadends);
		int len = 0;
		stack<vector<int>> stack;
		vector<int> first;
		first.push_back(0);
		stack.push(first);
		while (!stack.empty()) {
			vector<int> temp = stack.top();
			stack.pop();
			/*
			naozi youdian mi, wait
			basic idea:
			level by level, check if the target exists?
			*/
		}
	}
private:
	vector<vector<int>> setGraph(vector<string>& deadends) {
		vector<vector<int>> graph;
		for (int i = 0; i <= 9999; i++) {
			graph[i] = differOne(intToString(i), deadends);
		}
		return graph;
	}
	//a and b differ in one digit
	/*
	bool differOne(string s1, string s2) {
		int flag = false;
		for (int i = 0; i < 4; i++) {
			if (abs(s1[i] - s2[i]) == 1 || abs(s1[i] - s2[i]) == 9) {
				return true;
			}
		}
		return flag;
	}
	*/
	vector<int> differOne(string s, vector<string>deadends) {
		vector<int> res;
		vector<string>::iterator it;
		it = find(deadends.begin(), deadends.end(), s);
		if (it != deadends.end()) {
			return res;
		}
		for (int i = 0; i < 4; i++) {
			if (s[i] != '0') {
				string temp = s;
				temp[i] = s[i] - 1;
				if (find(deadends.begin(), deadends.end(), temp) == deadends.end()) {
					res.push_back(stoi(temp));
				}
			}
			else {
				string temp = s;
				temp[i] = '9';
				if (find(deadends.begin(), deadends.end(), temp) == deadends.end()) {
					res.push_back(stoi(temp));
				}
			}
			if (s[i] != '9') {
				string temp = s;
				temp[i] = s[i] + 1;
				if (find(deadends.begin(), deadends.end(), temp) == deadends.end()) {
					res.push_back(stoi(temp));
				}
			}
			else {
				string temp = s;
				temp[i] = '0';
				if (find(deadends.begin(), deadends.end(), temp) == deadends.end()) {
					res.push_back(stoi(temp));
				}
			}
		}
		return res;
	}
	string intToString(int val) {
		string s = to_string(val);
		if (s.size() < 4) {
			for (int i = 0; i < 4 - s.size(); i++) {
				s = "0" + s;
			}
		}
		return s;
	}
};