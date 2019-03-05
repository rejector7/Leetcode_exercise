/*
LC287
Find the Duplicate Number
*/
#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int size = nums.size();
		for (int i = 0; i < size-1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (nums[i] == nums[j])return nums[i];
				else continue;
			}
		}
		return -1;
	}
};

class Solution {
private:
	int findNum(int num, int lo, int hi, vector<int>&nums) {
		for (int i = lo; i < hi; i++) {
			if (nums[i] == num)return i;
			else continue;
		}
		return -1;
	}
public:
	int findDuplicate(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			if (findNum(nums[i], 0, i, nums) >= 0) return nums[i];
			else continue;
		}
	}
};

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		for (int i = 1; i < nums.size(); i++) {
			if (find(nums.begin(), nums.begin() + i, nums[i]) != nums.begin() + i) {
				return nums[i];
			}
			else continue;
		}
	}
};

/*
division
*/
class Solution {
private:
	int countLess(int mid, vector<int>&nums) {
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= mid)res++;
		}
		return res;
	}
public:
	int findDuplicate(vector<int>& nums) {
		int lo = 1, hi = nums.size() - 1;//from 1 to n
		int mid = 0;
		while (lo < hi) {
			mid = lo + (hi - lo) / 2;
			if (countLess(mid, nums) > mid) {
				hi = mid;
			}
			else {
				lo = mid + 1;
			}
		}
		return lo;
	}
};

/*
Floyd's Algorithm:Cycle detection wikipedia
It is too time-consuming to understand, so just remember the algorithm
OK:but I find it not too difficult, so I got it.
The proving procedure using some math knowledge which is not so easy.
Mapping-find-cycle
*/
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0;
		int fast = 0;
		do {
			slow = nums[slow];
			fast = nums[nums[fast]];
		} while (slow != fast);
		//get a new pointer from the beginning
		int find = 0;
		while (find != slow) {
			find = nums[find];
			slow = nums[slow];
		}

		return find;
	}
};