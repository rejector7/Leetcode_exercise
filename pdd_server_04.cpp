#include<iostream>
using namespace std;

#include<vector>
#include<string>
#include<stack>

class Solution {
public:
	vector<int> getMinInterval(vector<vector<int>> a){
		vector<int> res;
		int k = a.size();
		//attention: the arrays are sorted!
		
		//find the minimum of all arrays' max
		int minMax= a[0][a[0].size() - 1];
		//find the maximum of all arrays' min
		int maxMin = a[0][0];

		for (int i = 1; i < k; i++) {
			minMax = mini(minMax, a[i][a[i].size() - 1]);
			maxMin = maxi(maxMin, a[i][0]);
		}

		if (minMax <= maxMin) {
			res.push_back(minMax);
			res.push_back(maxMin);
		}
		else {
			res.push_back(maxMin);
			res.push_back(minMax);
		}
		return res;
	}
private:
	int mini(int a, int b) {
		return (a < b) ? a : b;
	}
	int maxi(int a, int b) {
		return (a > b) ? a : b;
	}
};