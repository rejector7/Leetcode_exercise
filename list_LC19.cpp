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
	ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* succ=head;
		int totalNum = 1;
		while (succ->next != NULL) {
			succ = succ->next;
			totalNum++;
		}
		//cout << totalNum;
		//ListNode* purpose;
		//ListNode* succ2 = head;
		int fromBegin = totalNum - n + 1;
		//cout << fromBegin;
		ListNode* pred = head;
		//only need next fromBegin-1 times
		//remove first num
		if (fromBegin==1) {
			/*
			head = head->next;
			return head;
			*/
			return head->next;
		}
		//else
		while (fromBegin-- > 2) {//first find the purpose's pred
			pred = pred->next;
		}
		//purpose = pred->next;
		//cout << purpose->val;
		//succ2 = purpose->next;
		pred->next = pred->next->next;
		return head;
	}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		//move n times
		ListNode* first = head;
		for (int i = 0; i < n; i++) {
			first = first->next;
		}
		if (first == NULL) {
			//it shows that remove the first node
			return head->next;
		}
		ListNode* second = head;
		//then the second only need to move total-n to get the node
		//and first move total-n to get end(NULL)
		//second need to move total-n-1 times to get the pred node
		while (first->next != NULL) {//totally totalNum-1 times
			first = first->next;
			second = second->next;
		}
		//now the second is the pred of the purpose node
		second->next = second->next->next;
		return head;
	}
};