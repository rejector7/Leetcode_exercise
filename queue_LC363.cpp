/*
Max sum of rectangle no larger than k
*/
#include<iostream>
using namespace std;

#include<vector>
/*
violently,but this only can get the sum equal to k
which is the max one no larger than k, I don't know how to define it.
OK, I know it.
another problem: it calculates the sum of whole values in the rectangle,
not just the four angles.
OK, I add them iterately.
one more problem, it can contain the same row or same col, but can not only one value.
...
can only be one value...
Oh, I am wrong, it means all the values, I still only calculate the line values.

OK, I try my best, but it still time limited... That's sad !
*/

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int row1 = 0, row2 = 1;
		int col1 = 0, col2 = 1;

		int sum = matrix[0][0];
		int off = (sum <= k) ? (k - sum) : -1;
		int res = k - off;

		//only one value.
		for (row1 = 0; row1 < matrix.size(); row1++) {
			for (col1 = 0; col1 < matrix[0].size(); col1++) {
				sum = matrix[row1][col1];
				if (sum == k) {
					return k;
				}
				//if (sum > k)break;  value can be negative
				else if (sum <k) {
					if (off == -1) {
						off = k - sum;
						res = sum;
					}
					else if (k - sum<off) {
						off = k - sum;
						res = sum;
					}
				}
				else  continue;
			}
		}

		//only one row, but two cols
		if(matrix[0].size()>=2){
			for (row1 = 0; row1 < matrix.size(); row1++) {
				for (col1 = 0; col1 < matrix[0].size()-1; col1++) {
					sum = matrix[row1][col1];
					for (col2 = col1 + 1; col2 < matrix[0].size(); col2++) {
						sum += matrix[row1][col2];
						if (sum == k) {
							return k;
						}
						//if (sum > k)break;  value can be negative
						else if (sum <k&&k - sum<off) {
							/*
							if (off == -1) {//this is impossible here.
							off = k - sum;
							res = sum;
							}*/
							off = k - sum;
							res = sum;
						}
						else  continue;
					}
				}
			}
		}
		//only one col, but two rows
		if (matrix.size() >= 2) {
			for (row1 = 0; row1 < matrix.size() - 1; row1++) {
				for (col1 = 0; col1 < matrix[0].size(); col1++) {
					sum = matrix[row1][col1];
					for (row2 = row1 + 1; row2 > matrix.size(); row2++) {
						sum += matrix[row2][col1];
						if (sum == k) {
							return k;
						}
						//if (sum > k)break;  value can be negative
						else if (sum <k&&k - sum<off) {
							/*
							if (off == -1) {//this is impossible here.
							off = k - sum;
							res = sum;
							}*/
							off = k - sum;
							res = sum;
						}
						else  continue;
					}
				}
			}
		}
		//two rows, two cols
		for (row1 = 0; row1 < matrix.size()-1; row1++) {
			 for (row2 = row1 + 1; row2 < matrix.size(); row2++) {
				 
				 for (col1 = 0; col1 < matrix[0].size() - 1; col1++) {
					 sum = 0;
					 for (int i = row1; i <= row2; i++) {
						 sum += matrix[i][col1];//col1's sum
					 }
					 for (col2 = col1 + 1; col2 < matrix[0].size(); col2++) {
						for (int i = row1; i <= row2; i++) {
								sum += matrix[i][col2];
						}
						if (sum == k) {
							return k;
						}
						//if (sum > k)break;  value can be negative
						else if (sum <k) {
							if (off == -1) {
								off = k - sum;
								res = sum;
							}
							else if (k - sum<off) {
								off = k - sum;
								res = sum;
							}
						}
						else  continue;
					}
				}
			}
		}
		return res;
	}
};

