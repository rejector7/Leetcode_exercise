#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<functional>
#include<algorithm>
/*
first idea is replace from tail to head
but the index is not sorted..
*/
class Solution {
private:
	bool myfunction(int i, int j) {
		return i < j;
	}
public:
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
		/*
		only need the maximum index, can use a priority queue
		or a hashmap which have a sorted key
		*/
		/*
		terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc

  change to hashmap
		
		priority_queue<int, vector<int>, less<int>> pq;
		for (int i = 0; i < indexes.size(); i++) {
			pq.push(indexes[i]);
		}
		*/
		//sort(indexes.begin(), indexes.end(), myfunction);
		/*
		quick sort will change the corresponding relation
		*/
		
		/*
		int i;
		while (!pq.empty()) {
			i = pq.top();
			pq.pop();
			if (i+sources[i].size()<=S.size()&&S.substr(i, sources[i].size()) == sources[i]) {
				S.replace(i, sources[i].size(), targets[i]);
			}
		}
		*/
		
		map<int, int>in;
		for (int i = 0; i < indexes.size(); i++) {
			in.insert(pair<int,int>(indexes[i], i));
		}
		map<int, int>::reverse_iterator it;
		for (it = in.rbegin(); it != in.rend(); it++) {
			int index = it->first;
			int i = it->second;
			if(S.substr(index, sources[i].size()) == sources[i]) {
				S.replace(index, sources[i].size(), targets[i]);
			}
		}
		
		return S;
	}
};