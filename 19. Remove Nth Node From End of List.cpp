/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	vector <ListNode*> positions;
    	while(head != NULL){
    		positions.push_back(head);
    		head = head->next;
		}
    	int vectorLength = positions.size(),
			positionToRemove = vectorLength - n;
			
		if(vectorLength == 1)return NULL;
		else if(positions[positionToRemove]->next == NULL)positions[positionToRemove-1]->next = NULL;
		else if (positionToRemove == 0)positions[0] = positions[1];
		else positions[positionToRemove-1]->next = positions[positionToRemove+1];
		
    	return positions[0];
    }
    
    void chceckSolution(){
    	ListNode *list = new ListNode(1);
    	ListNode *list2 = new ListNode(2);
    	ListNode *list3 = new ListNode(3);

    	list->next = list2;
    	list2->next = list3;
    	printList(removeNthFromEnd(list, 3));
	}
	
	void printList(ListNode* head){
		cout<<head->val;
		if(head->next != NULL)printList(head->next);
	}
};

int main(){
	Solution a;
	a.chceckSolution();
}
