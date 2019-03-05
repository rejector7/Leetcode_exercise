/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
#include<iostream>
using namespace std;

#include<vector>
#include<math.h>
#include<stack>
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int min(int a, int b) {
	return (a < b) ? a : b;
}
/*
I ignore the difference between the subtrees.
And I even do not understand that what features the binary tree have.
*/
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		
		//add a virtual root  //make no sense, I give it up...
		TreeNode* dummy = new TreeNode(-1);
		dummy->left = NULL;
		dummy->right = root;
		return getMinimum(dummy);
	}
private:
	int getMinimum(TreeNode* root) {
		int res = INT_MAX;
		int leftVal, rightVal;
		//one edge leaf node
		if (root == NULL)return INT_MAX;
		//have left and right nodes
		leftVal = getMinimumDifference(root->left);
		rightVal = getMinimumDifference(root->right);
		//min in left and right subtree, not contain the root node
		res = min(leftVal, rightVal);

		int rootVal = root->val;
		int rootDiff = compareRoot(rootVal, root);
		return min(res, rootVal);
	}
	int compareRoot(int rootVal, TreeNode* root) {
		//leaf node
		if (root ->left== NULL&&root->right==NULL) {
			return abs(rootVal - root->val);
			//attention, here two rootval are not the same one.
		}
		if (root->left->left == NULL && root->left->right == NULL && root->right->left == NULL
			&& root->right->right == NULL) {

		}
		int left = INT_MAX;
		int right = INT_MAX;
		if (root->left != NULL) {
			left = compareRoot(rootVal, root->left);
		}
		if (root->right != NULL) {
			right = compareRoot(rootVal, root->right);
		}
		return min(min(left, right), abs(rootVal - root->val));
	}
};

class Solution {
private:
	void getInorder(vector<int>&inque, TreeNode* root) {
		if (!root)return;
		getInorder(inque, root->left);
		inque.push_back(root->val);
		getInorder(inque, root->right);
	}
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root)return 0;
		vector<int> inOrder;
		getInorder(inOrder, root);
		int res = INT_MAX;
		for (int i = 1, n = inOrder.size(); i < n; i++)
			if ((inOrder[i] - inOrder[i - 1]) < res)
				res = inOrder[i] - inOrder[i - 1];
		return res;
	}
};
/*
Attention:
the minimun difference only happen in two cases:
1. left node's parent and its right successor(not just child)
2. left node itself and its parent.

mid-order travesal
*/
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		int res = INT_MAX;
		if (root == NULL)  return res;
		stack<TreeNode*> sk;
		TreeNode* pre = nullptr;
		TreeNode* suc = nullptr;
		while (true) {
			// push the left child into the stack
			while (root) {
				sk.push(root);
				root = root->left;
			}
			// exit if empty
			if (sk.empty()) break;
			
			root = sk.top();
			sk.pop();
			suc = (!sk.empty()) ? sk.top() : nullptr;
			// pre is the closest value which is smaller than root.
			if (pre) res = min(res, abs(root->val - pre->val));
			//succ is larger than root.
			if (suc) res = min(res, abs(root->val - suc->val));
			//if right child exists, push into the stack, so we get the mid-order travesal.
			pre = root;
			root = root->right;
		}
		return res;
	}
};