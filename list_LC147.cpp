/*
Insertion Sort List
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
/*
What's the problem?
*/
class Solution {
public:
	ListNode * insertionSortList(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		//only one node
		if (head->next == NULL)return head;
		//else
		dummy->next = head;
		int lastMax = head->val;
		ListNode* cur = head->next;//from the second node
		ListNode* endPre = head;
		ListNode*pre;
		ListNode* temp;
		while (cur != NULL) {
			if (cur->val >= lastMax) {
				lastMax = cur->val;
				endPre = cur;
				cur = cur->next;
				continue;
			}
			pre = dummy;
			while (pre->next!=NULL&&pre->next->val < cur->val) {
				pre = pre->next;
			}
			temp = cur;
			endPre->next = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = temp->next;
		}
		return dummy->next;
	}
};

/*
Net solution
*/
class Solution {
public:
	ListNode * insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}
		//create a new list
		ListNode* pre = new ListNode(-1);
		//save the head node
		ListNode*ans = pre;
		//cur is the node in the old list
		ListNode* cur = head;
		while (cur != NULL) {
			pre = ans;
			while (pre->next != NULL && pre->next->val < cur->val) {
				pre = pre->next;
			}
			ListNode* temp = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			cur = temp;
		}
		return ans->next;
	}
};