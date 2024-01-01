#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    this->data = data;
    left = right = nullptr;
  }
};
class Solution
{
public:
  void solve(Node *root)
  {
    queue<Node *> q;
    q.push(root);
    int h = 0;
    int sz = 0;
    while (!q.empty())
    {
      h++;
      int num = q.size();
      while (num--)
      {
        Node *current = q.front();
        sz++;
        q.pop();
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
    }
    cout << sz << " " << h << "\n";
  }
};
int main()
{
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->right->left = new Node(7);
  root->right->right = new Node(6);
  Solution MyTree;
  MyTree.solve(root);
}