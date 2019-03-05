/*
LC11
container with most water
*/
#include <iostream>
using namespace std;

#include <vector>
class Solution {
private:
	int min(int a, int b) {
		return (a < b) ? a : b;
	}

public:
	int maxArea(vector<int>& height) {
		//the most left and right height
		int heightMin = height[0], heightMax = height[height.size() - 1];
		int area = min(heightMin, heightMax)*(height.size() - 1);
		int temp = 0;
		int left = heightMin;

		for (int i = 0; i < height.size()-1; i++) {

			if (height[i] <left) continue;
			int right = heightMax;
			
			for (int j = height.size() - 1; j >= i + 1; j--) {
				if (height[j] < right) {
					continue;
				}

				temp = min(height[i], height[j]) * (j - i);
				if (temp >= area) {
					area = temp;
					right = height[j];
					left = height[i];
				}
				else continue;
			}
		}
		return area;
	}
};
