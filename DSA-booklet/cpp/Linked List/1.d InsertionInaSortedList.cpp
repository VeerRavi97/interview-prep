#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// memory Pool
Node *InsertInSortedList(Node *head, int height)
{
    Node *newNode = new Node(height);
    if (!head || height <= head->data) // Insertion at begining
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *curr = head;
    Node *pre = NULL;
    while (curr->next && curr->next->data <= height)
    {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main()
{
    int n;
    cin >> n;
}