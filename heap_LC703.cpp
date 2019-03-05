#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
/*
basic idea is 
save a k-size min heap
the kLargest element is the heap top
*/

/*
some pointer problem
the basic idea is ok
*/
class KthLargest {
private:
	int size;
	vector<int> kHeap;
public:
	KthLargest(int k, vector<int> nums) {
		int len = nums.size();
		int i = (k - 1 - 1) / 2;//i=lastInternal
		//bottom-up percolateDown
		while (i >= 0) {
			int tempi = i;
			int temp = nums[i];
			int j = i * 2 + 1;
			while (j < k&&j<len) {
				if (j + 1 < k&&j+1<len&&nums[j + 1] < nums[j]) {
					j++;
				}
				if (nums[j] >= temp) {
					break;
				}
				nums[i] = nums[j];
				i = j;
				j = 2 * i + 1;
			}
			nums[i] = temp;
			i = tempi - 1;
		}
		if (len > k) {
			for (int l = k; l < len; l++) {
				if (nums[l] <= nums[0])
					continue;
				nums[0] = nums[l];
				int tmp = nums[0];
				i = 0;
				int j = i * 2 + 1;
				while (j < k) {
					if (j + 1 < k && nums[j + 1] < nums[j])
						j++;
					if (nums[j] >= tmp)
						break;
					nums[i] = nums[j];
					i = j;
					j = i * 2 + 1;
				}
				nums[i] = tmp;
			}
		}
		

		size = k;
		for (int i = 0; i < k; i++) {
			kHeap[i] = nums[i];
		}
	}

	int add(int val) {
		if (val <= kHeap[0]) {
			return kHeap[0];
		}
		kHeap[0] = val;//the min deleted
		int i = 0;
		int j = i * 2 + 1;
		
		while (j < size) {
			if (j + 1 < size&&kHeap[j + 1] < kHeap[j]) {
				j++;
			}
			if (kHeap[j] >= kHeap[i]) {
				break;
			}
			kHeap[i] = kHeap[j];
			i = j;
			j = i * 2 + 1;
		}
		kHeap[i] = val;
		return kHeap[0];
	}
};
/*
use container priority_queue
*/

class KthLargest {
public:
	KthLargest(int k, vector<int> nums) {
		size = k;
		for (auto num : nums) {
			pq.push(num);
			if (pq.size() > size)
				pq.pop();
		}
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > size)
			pq.pop();
		return pq.top();
	}
private:
	priority_queue<int, vector<int>, greater<int> > pq;
	int size;
};