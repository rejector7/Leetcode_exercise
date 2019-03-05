#include<iostream>
using namespace std;

#include<vector>
#include<math.h>
#include<set>
/*
first solution:
forcing solution : O(kn-k*k)

OK,,, time exceeded!
*/
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() < 2) {
			return false;
		}
		long minDiff = 0;
		// size<=k
		if (nums.size() <= k) {
			minDiff = LONG_MAX;
			for (int i = 0; i < nums.size()-1; i++) {
				for (int j = i+1; j < nums.size(); j++) {
					minDiff = mini(minDiff, abs((long)nums[i] - (long)nums[j]));
				}
			}
			if (minDiff <= t)return true;
			else return false;
		}
			//each k+1 num a group
		for (int i = 0; i < nums.size() - k ; i++) {
			minDiff = LONG_MAX;
			for (int j = i; j < i + k; j++) {
				for (int l = j + 1; l <= i + k; l++) {
					minDiff = mini(minDiff, abs((long)nums[l] - (long)nums[j]));
					if (minDiff <= t)return true;
				}
			}
			if (minDiff <= t)return true;
		}
		return false;
	}
private:
	long mini(long a, long b) {
		return (a < b) ? a : b;
	}
};

/*
I know the solution is about BST
thinking...

i don't think it is a BST, it is even not a tree..
it is just binary search..


*/

//....  HOLY GOD
/*
二叉排序树的数据结构set
提供了一个函数lower_bound，可以查找树中第一个大于等于某值的位置

another problem is the int limitation, we need long
*/
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		/*
		vector<long> longNums;
		for (int i = 0; i < nums.size(); i++) {
			longNums[i] = (long)nums[i];
		}
		*/
		if (nums.size() < 2) return false;
		multiset<long> st;
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > k) st.erase(st.find(nums[i - k - 1]));//remove the oldest one
			auto it = st.lower_bound((long)nums[i] -(long) t);//the other situation is that the it is too bigger
			//so need the second check
			if (it != st.end() && abs((long)*it - (long)nums[i]) <= (long)t) return true;
			st.insert(nums[i]);
		}
		return false;
	}
};