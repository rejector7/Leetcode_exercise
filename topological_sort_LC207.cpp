#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<queue>
//...
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> visited;
		//init
		for (int i = 0; i < numCourses; i++) {
			visited[i] = 0;
		}
		stack<int> res;//in fact not need
		stack<int> stack;
		int flag = 0;
		int index = 0;
		while (index < numCourses) {
			if (visited[index] == 0) {
				return DFS(index, stack, prerequisites,visited);
			}
			else {
				continue;
			}
		}
	}
private:
	bool DFS(int index, stack<int> &stack, vector<pair<int, int>>& prerequisites,vector<int> visited) {
		stack.push(index);
		int cur = stack.top();
		int flag = 0;
		for (int i = 0; prerequisites.size(); i++) {
			if (prerequisites[i].first == cur && visited[prerequisites[i].second] == 1) {
				return false;
			}
			if (prerequisites[i].first == cur&&visited[prerequisites[i].second]==0) {
				DFS(prerequisites[i].second, stack, prerequisites, visited);
				flag = 1;
				break;
			}
			else continue;
		}
		if (flag == 0) {
			visited[cur] = 1;
		}
		

	}
};
/*
 auto pointer!
 net solution
*/
class Solution {
public:
	//can finish as long as there is no circle
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > graph(numCourses, vector<int>(0)); //存储有向图
		vector<int> visit(numCourses, 0); //记录访问状态
		for (auto a : prerequisites) { //初始化有向图
			graph[a.second].push_back(a.first);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!canFinishDFS(graph, visit, i)) return false;
		}
		return true;
	}
	bool canFinishDFS(vector<vector<int> > &graph, vector<int> &visit, int i) {
		if (visit[i] == -1) return false;//if we get -1, it means a circle
		if (visit[i] == 1) return true;
		visit[i] = -1;//stand for this time's search root!
		for (auto a : graph[i]) {
			if (!canFinishDFS(graph, visit, a)) return false;
		}
		visit[i] = 1;
		return true;
	}
};

