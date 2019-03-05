#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>
#include<queue>
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res(n); // 记录输出结果
		int k = primes.size();
		/*
		pos means
		each prime need to multiple one of the res_before,
		pos records the next pos this prime need to multiple
		because each ugly num is the  multiple res of before-num in res
		*/
		vector<int> pos(k, 0); // 记录每一个prime质数已经乘过的位置
		int i, j, temp;
		res[0] = 1; // 1是固定的起始位置
		for (i = 1; i < n; i++) {
			temp = INT_MAX;
			for (j = 0; j < k; j++) {
				temp = min(temp, res[pos[j]] * primes[j]);
			}
			for (j = 0; j < k; j++) {
				if (temp == res[pos[j]] * primes[j])
					pos[j]++;
			}// 这个for循环是为了找出上一轮中所有的最小值，所有都加一，消除重复，否则下一轮最小还是它
			res[i] = temp;
		}

		return res[n - 1];
	}
};

struct Node {
	int index, val, prime;
	Node(int in, int va, int pr) {
		index = in;
		val = va;
		prime = pr;
	}
	bool operator < (const Node& b) const {
		return val > b.val;
	} // 新定义这个大于变小于只是为了把priority queue里默认的maxheap改成minheap，也可在定义处改
};

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res(n);
		priority_queue<Node> q;
		res[0] = 1;
		int k = primes.size();
		for (int i = 0; i < k; i++) {
			q.push(Node(0, primes[i], primes[i]));
		} // 把所有的prime归置到这个queue里，0代表目前大家的index，val等于prime基本值因为输出第一     
		  // 个是1, prime[i]乘以1还是自己
		for (int i = 1; i < n; i++) {
			Node cur = q.top();
			res[i] = cur.val; //直接将最小的赋值给输出现有位置
			do {
				cur = q.top();//再取一次是因为如果产生循环，第二次的cur需要重新取新的top
				q.pop();
				cur.val = cur.prime*res[++cur.index];
				q.push(cur);
			} while (!q.empty() && q.top().val == res[i]);
		}// 先执行再判断，避免有多个相同最小值

		return res[n - 1];
	}
};