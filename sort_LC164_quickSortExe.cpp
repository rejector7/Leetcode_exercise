/*
Maximum Gap
*/
#include<iostream>
using namespace std;
#include<vector>

/*
.quicksortExercise
*/

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		quickSort(nums, 0, nums.size());
		int res = 0;
		int time = nums.size() - 1;
		int i = 0;
		/*
		while (time-- > 0) {
			res = max(res, nums[++i] - nums[i]);
		}
		*/
		for (int i = 0; i <= time; i++) {
			printf("%d", nums[i]);
		}
		return res;
	}
private:
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	/*
	quick sort for exercise
	*/
	/* open interval */
	void quickSort(vector<int> &nums, int low, int high) {
		if (high - low < 2)return;
		int mid = partition(nums, low, high-1);
		quickSort(nums, low, mid);
		quickSort(nums, mid + 1, high);
	}
	/* closed interval*/
	int partition(vector<int> &nums, int low, int high) {
		int randIndex = low + rand() % (high - low + 1);
		swap(nums[low], nums[randIndex]);

		int pivot = nums[low];
		while (low < high) {
			while (low < high&&nums[high] >= pivot) {
				high--;
			}
			nums[low] = nums[high];

			while (low < high&&nums[low] <= pivot) {
				low++;
			}
			nums[high] = nums[low];
		}
		nums[low] = pivot;
		return low;
	}
	void swap(int &a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
};

int main() {
	Solution so;
	vector<int> nums = { 3,6,9,1,3,7,4 };
	so.maximumGap(nums);
	system("pause");
	return 0;
}

/* 
for the LC question
Try to solve it in linear time/space

Bucket Sort, I will be back after reviewing the bucket sort.
*/
class Solution {
public : 
	int maximumGap(vector<int> &nums) {
		if (nums.size() < 2) {
			return 0;
		}

	}
};