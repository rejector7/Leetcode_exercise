/**
* // This is the interface that allows for creating nested lists.
* // You should not implement it, or speculate about its implementation
* class NestedInteger {
*   public:
*     // Constructor initializes an empty nested list.
*     NestedInteger();
*
*     // Constructor initializes a single integer.
*     NestedInteger(int value);
*
*     // Return true if this NestedInteger holds a single integer, rather than a nested list.
*     bool isInteger() const;
*
*     // Return the single integer that this NestedInteger holds, if it holds a single integer
*     // The result is undefined if this NestedInteger holds a nested list
*     int getInteger() const;
*
*     // Set this NestedInteger to hold a single integer.
*     void setInteger(int value);
*
*     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
*     void add(const NestedInteger &ni);
*
*     // Return the nested list that this NestedInteger holds, if it holds a nested list
*     // The result is undefined if this NestedInteger holds a single integer
*     const vector<NestedInteger> &getList() const;
* };
*/

#include<iostream>
using namespace std;
#include<string>
#include<stack>
#include<vector>
class NestedInteger {
public:
	NestedInteger();
	NestedInteger(int value);
	bool isInteger() const;
	int getInteger() const;
	void setInteger(int value);
	// Set this NestedInteger to hold a nested list and adds a nested integer to it.
	void add(const NestedInteger &ni);
	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};
/*
class Solution {
public:
	NestedInteger deserialize(string s) {
		stack<NestedInteger> stack;
		int i = 0;
		NestedInteger  res, temp;
		int num = 0;
		int sign = 1;
		while (i < s.length()) {
			char c = s[i];
			switch (c) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				num = num * 10 + c - '0';
				i++;
			case '-':
				sign = -1;
				i++;
			case '[':
				num = 0;
				sign = 1;
				i++;
			case ',':
				temp.setInteger(sign*num);
			case ']':

					

			}
		}
	}
};
*/

class Solution {
public:
	NestedInteger deserialize(string s) {
		if (s.empty()) return NestedInteger();
		if (s[0] != '[') return NestedInteger(stoi(s));
		if (s.size() <= 2) return NestedInteger();
		NestedInteger res;
		int start = 1, cnt = 0;
		for (int i = 1; i < s.size(); ++i) {
			if (cnt == 0 && (s[i] == ',' || i == s.size() - 1)) {
				res.add(deserialize(s.substr(start, i - start)));
				start = i + 1;
			}
			else if (s[i] == '[') ++cnt;
			else if (s[i] == ']') --cnt;
		}
		return res;
	}
};