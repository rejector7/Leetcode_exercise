/*
reverse nodes in k-Group
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include<iostream>
using namespace std;
#include<list>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

//my solution , not complete, it is too massive to manage the whole procedure.
//so I decided to reference some codes on the Net...
/*
class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (k == 1) {
			return head;
		}
		//else k>=2
		ListNode* temp = head;
		int totalNum = 1;
		while (temp ->next != NULL) {
			temp = temp->next;
			totalNum++;
		}
		
		int groups = totalNum / k;
		int remainder = totalNum - k * groups;
		ListNode* kBegin = head;
		ListNode* first = head;
		ListNode* second = head;
		//the first group
		for (int j = 0; j < k / 2; j++) {
			while (k-- > j + 2) {//get the pred
				first = first->next;
			}
			while (j-- > 0) {
				second = second->next;
			}
		}

		for (int i = 1; i < groups; i++) {
			for (int j = 0; j < k/2; j++) {
				while (k-- > j+2) {//get the pred
					first = first->next;
				}
				while (j-- > 0) {
					second = second->next;
				}
			}
			
		}
	}
};
*/

//Net solution
//new a dummy node in the beginning
class Solution {
public:
	ListNode * reverseKGroup(ListNode *head, int k) {
		if (!head || k == 1)return head;
		ListNode *dummy = new ListNode(-1);
		ListNode *pre = dummy, *cur = head;
		dummy->next = head;
		int i = 0;
		while (cur != NULL) {
			i++;
			if (i%k == 0) {
				pre = reverseOneGroup(pre, cur->next);
				cur = pre->next;
			}
			else cur = cur->next;
		}
		return dummy->next;
	}
	// a reverse algorithm!!
	/*
		one time once node, move to the beginning.
	*/
private:
	ListNode * reverseOneGroup(ListNode *pre, ListNode *next) {
		ListNode*last = pre->next;
		ListNode*cur = last->next;
		while (cur != next) {
			last->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = last->next;
		}
		return last;
	}
};