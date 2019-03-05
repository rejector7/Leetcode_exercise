#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>
#include<queue>
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> res(n); // ��¼������
		int k = primes.size();
		/*
		pos means
		each prime need to multiple one of the res_before,
		pos records the next pos this prime need to multiple
		because each ugly num is the  multiple res of before-num in res
		*/
		vector<int> pos(k, 0); // ��¼ÿһ��prime�����Ѿ��˹���λ��
		int i, j, temp;
		res[0] = 1; // 1�ǹ̶�����ʼλ��
		for (i = 1; i < n; i++) {
			temp = INT_MAX;
			for (j = 0; j < k; j++) {
				temp = min(temp, res[pos[j]] * primes[j]);
			}
			for (j = 0; j < k; j++) {
				if (temp == res[pos[j]] * primes[j])
					pos[j]++;
			}// ���forѭ����Ϊ���ҳ���һ�������е���Сֵ�����ж���һ�������ظ���������һ����С������
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
	} // �¶���������ڱ�С��ֻ��Ϊ�˰�priority queue��Ĭ�ϵ�maxheap�ĳ�minheap��Ҳ���ڶ��崦��
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
		} // �����е�prime���õ����queue�0����Ŀǰ��ҵ�index��val����prime����ֵ��Ϊ�����һ     
		  // ����1, prime[i]����1�����Լ�
		for (int i = 1; i < n; i++) {
			Node cur = q.top();
			res[i] = cur.val; //ֱ�ӽ���С�ĸ�ֵ���������λ��
			do {
				cur = q.top();//��ȡһ������Ϊ�������ѭ�����ڶ��ε�cur��Ҫ����ȡ�µ�top
				q.pop();
				cur.val = cur.prime*res[++cur.index];
				q.push(cur);
			} while (!q.empty() && q.top().val == res[i]);
		}// ��ִ�����жϣ������ж����ͬ��Сֵ

		return res[n - 1];
	}
};