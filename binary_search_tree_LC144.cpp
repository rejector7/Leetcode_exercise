#include<iostream>
using namespace std;

#include <vector>
#include<stack>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};


/*
beats 100%
*/
class Solution {
public :
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stack;
		goAlongLeftBranch(stack, root, res);
		while (!stack.empty()) {
			TreeNode* n = stack.top();
			stack.pop();
			if (n->right != NULL) {
				goAlongLeftBranch(stack, n->right, res);
			}
		}
		return res;
	}
private:
	void goAlongLeftBranch(stack<TreeNode*> &stack, TreeNode* root, vector<int> &res) {
		while (root) {
			stack.push(root);
			res.push_back(root->val);
			root = root->left;
		}
	}
};