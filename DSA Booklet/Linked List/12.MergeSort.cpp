#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *head, int val)
    {
        Node *nn = new Node(val);
        if (!head)
        {
            head = nn;
            return head;
        }
        Node *ptr = head;
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = nn;
        return head;
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
    void split(Node *head, Node **aref, Node **bref)
    {
        Node *pre = NULL;
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast)
            slow = pre;
        *bref = slow->next;
        slow->next = NULL;
        *aref = head;
        return;
    }
    Node *merge(Node *a, Node *b)
    {
        if (!a && !b)
            return nullptr;
        if (!a && b)
            return b;
        if (a && !b)
            return a;
        Node *result = NULL;
        if (a->val < b->val)
        {
            result = a;
            result->next = merge(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }

    void *MergeSort(Node **headref)
    {
        Node *head = *headref;
        if (!head || !head->next)
            return head;
        Node *a = NULL;
        Node *b = NULL;
        split(head, &a, &b);
        MergeSort(&a);
        MergeSort(&b);
        *headref = merge(a, b);
    }
};
int main()
{
    Node *head = NULL;
    Solution obj;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        head = obj.insert(head, in);
    }
    obj.MergeSort(&head);
    obj.display(head);
}
