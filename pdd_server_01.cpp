#include<iostream>
using namespace std;

#include<vector>
class Solution {
public:
	vector<vector<int>>  getMaxOne(vector<vector<int>> matrix) {
		vector<vector<int>> res;
		int max = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		//get the first line to initiate the max value
		//O(n)
		for (int i = n - 1; i >= 0; i++) {
			if (matrix[0][i] == 1) {
				max++;
				continue;
			}
			else break;
		}
		//line 1 to m-1
		int index = n - max - 1;
		//O(m+n)
		for (int i = 1; i <= m - 1; i++) {
			if (matrix[i][index] == 0)continue;
			else {
				max++;
				index--;
			}
		}
		int lastOneIndex = n - max;
		//O(m)
		for (int i = 0; i < m; i++) {
			if (matrix[i][lastOneIndex] == 1) {
				vector<int> pair;
				pair.push_back(i);
				pair.push_back(max);
				res.push_back(pair);
			}
		}
		return res;
	}
	/*
		total: O(m+n)
	*/
};