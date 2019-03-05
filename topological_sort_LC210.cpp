#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<queue>

/*
who complete visit, who push into the stack first!
complelte visit: all neighbour are visited
*/
class Solution {
public:
	//can finish as long as there is no circle
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		stack<int> res;
		vector<vector<int> > graph(numCourses, vector<int>(0)); //存储有向图
		vector<int> visit(numCourses, 0); //记录访问状态
		for (auto a : prerequisites) { //初始化有向图
			graph[a.second].push_back(a.first);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!canFinishDFS(graph, visit, i, res)) {
				vector<int> emptyV;
				return emptyV;
			}
		}
		vector<int> ret;
		while (!res.empty()) {
			ret.push_back(res.top());
			res.pop();
		}
		return ret;
	}
private:
	bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i, stack<int> &res) {
		if (visit[i] == -1) return false;//if we get -1, it means a circle
		if (visit[i] == 1) return true;
		visit[i] = -1;//stand for this time's search root!
		for (auto a : graph[i]) {
			if (!canFinishDFS(graph, visit, a,res)) return false;
		}
		visit[i] = 1;
		res.push(i);
		return true;
	}
};
