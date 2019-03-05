#include<iostream>
using namespace std;
#include<vector>
#include<stack>

/*
Longest Increasing Path in a Matrix
*/
//no good idea, it seems  dynamic programming..
class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		int maxLen = 1;
		//init
		vector<vector<int>> visited;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				visited[i][j] == 0;
			}
		}
		int x = 0;
		int y = 0;
		stack<int> stack;


		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				int curValue = matrix[i][j];
				int curLen = 1;

			}
		}
	}
};
