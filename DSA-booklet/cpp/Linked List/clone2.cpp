#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
	int val;
	Node *next;
	Node *random;
	Node(int val)
	{
		this->val = val;
		this->next = NULL;
		this->random = NULL;
	}
};
class Solution
{

public:
	Node *insert(Node *head, int val)
	{
		Node *nn = new Node(val);
		if (!head)
			return nn;
		Node *ptr = head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = nn;
		return head;
	}

	void displaywithRandom(Node *head)
	{
		Node *ptr = head;
		while (ptr)
		{
			cout << ptr->val << " " << ptr->random->val << "\n";
			ptr = ptr->next;
		}
		cout << "\n";
	}
	void display(Node *head)
	{
		Node *ptr = head;
		while (ptr)
		{
			cout << ptr->val << " ";
			ptr = ptr->next;
		}
		cout << "\n";
	}

	Node *swap(Node *a, Node *b)
	{
		a->next = b;
		b->next = a;
		return b;
	}

	Node *clone2(Node *head)
	{
		if (!head)
			return head;
		Node *curr = head;
		while (curr)
		{
			Node *next = curr->next;
			Node *nn = new Node(curr->val);
			curr->next = nn;
			nn->next = next;
			curr = next;
		}
		//display(head);
		curr = head;
		while (curr && curr->next)
		{

			Node *next = curr->next->next;
			if (curr->random)
				curr->next->random = curr->random->next;
			curr = next;
		}
		curr = head;
		Node *clonedcurr = head;
		Node *cloned_head = curr->next;
		while (curr && clonedcurr)
		{

			curr->next = clonedcurr->next;
			if (clonedcurr->next)
				clonedcurr->next = clonedcurr->next->next;
			// cout << cloned->val << "\n";
			curr = curr->next;
			clonedcurr = clonedcurr->next;
		}

		return cloned_head;
	}
};

int main()
{
	Node *head = NULL;
	Solution A;
	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->random = head->next->next->next;						   // 4
	head->next->random = head->next->next;						   // 3
	head->next->next->random = head;							   // 1
	head->next->next->next->random = head->next->next->next->next; //5
	head->next->next->next->next->random = head->next;			   // 2

	//A.display(head);
	head = A.clone2(head);
	A.displaywithRandom(head);
}