#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<queue>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};
/*
I make it more complex
*/
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		
	}
private:
	//one vector by one to push into the res_vector
	void BFS(queue<vector<TreeNode*>>&queue, TreeNode* root,vector<vector<int>> &res) {
		vector<TreeNode* > level;
		level.push_back(root);
		queue.push(level);
		while (queue.empty()) {
			vector<TreeNode*>levelNode = queue.front();
			queue.pop();
			for (int i = 0; i < levelNode.size(); i++) {
				vector<int> levelRes;
				levelRes.push_back(levelNode[i]->val);
			}
			vector<vector<int>>::iterator it=res.begin();
			res.insert(it, 0);
			vector<TreeNode*> nextLevel;
			for (int i = 0; i < levelNode.size(); i++) {
				if (levelNode[i]->left != NULL)nextLevel.push_back(levelNode[i]->left);
				if (levelNode[i]->right != NULL)nextLevel.push_back(levelNode[i]->right);

			}
			queue.push(nextLevel);

			
			

		}
	}
};
/*
first implement an easy way
just by a stack
before use some reference, please judge that they are not null!!!
*/
class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {

		vector<vector<int>> res;
		if (root == NULL) {

			return res;
		}
		stack<vector<TreeNode*>> stack;
		vector<TreeNode*> curLevel;
		curLevel.push_back(root);
		stack.push(curLevel);
		int flag = 1;//still have some level nodes left
		while (flag) {
			flag = 0;
			vector<TreeNode*> tempLevel = stack.top();
			vector<TreeNode*> nextLevel;
			if (!tempLevel.empty()) {
				for (int i = 0; i < tempLevel.size(); i++) {
					if (tempLevel[i] != NULL && tempLevel[i]->left != NULL) {
						nextLevel.push_back(tempLevel[i]->left);
						flag = 1;
					}
					if (tempLevel[i] != NULL && tempLevel[i]->right != NULL) {
						nextLevel.push_back(tempLevel[i]->right);
						flag = 1;
					}
				}
				if (flag == 1) {
					stack.push(nextLevel);
				}
			}
		}
		while (!stack.empty()) {
			vector<int>levelVal;
			vector<TreeNode*> topLevel = stack.top();
			stack.pop();
			for (int i = 0; i < topLevel.size(); i++) {
				if (topLevel[i] != NULL) {
					levelVal.push_back(topLevel[i]->val);
				}

			}
			res.push_back(levelVal);
		}
		return res;
	}
};