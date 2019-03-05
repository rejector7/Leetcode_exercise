/*
LC11
container with most water
*/
#include <iostream>
using namespace std;

/*
I see this idea from the Net, but i don't think it is right
althouth this pass the test.
Problem: if two number are equal ,and this move the wrong line, we will get the wrong answer.
Answer: I am wrong, because the min line matters.
IF the maxArea is concerned with the two equal lines, then the area will not larger than the area which 
formed by the two equal lines. So which one to move does not matter.
*/
#include <vector>
class Solution {
private:
	int min(int a, int b) {
		return (a < b) ? a : b;
	}
	int max(int a, int b) {
		return(a > b) ? a : b;
	}
public:
	int maxArea(vector<int>& height) {
		int area = 0;
		int temp = 0;
		int i = 0, j =height.size() - 1;
		while (i < j) {
			temp = min(height[i], height[j])*(j - i);
			area = max(temp, area);
			if (height[i] < height[j])i++;
			else j--;
		}
		
		return area;
	}
};
