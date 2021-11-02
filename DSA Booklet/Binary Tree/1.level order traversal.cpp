#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int node_data)
  {
    this->data = node_data;
    left = right = NULL;
  }
};
class Solution
{
public:
  void levelorder(Node *root)
  {
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
      Node *current = q.front();
      q.pop();
      cout << current->data << " ";
      if (current->left)
        q.push(current->left);
      if (current->right)
        q.push(current->right);
    }
  }
  vector<vector<int>> levelOrder(Node *root)
  {
    queue<Node *> q;
    vector<vector<int>> v;
    vector<int> temp;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
      Node *curr = q.front();
      q.pop();
      if (!curr)
      {
        v.push_back(temp);
        temp.clear();
        // cout << endl;
        if (q.size() > 0)
          q.push(nullptr);
      }
      else
      {
        temp.push_back(curr->data);
        if (curr->left)
          q.push(curr->left);
        if (curr->right)
          q.push(curr->right);
      }
    }
    for (auto x : v)
    {
      for (auto y : x)
      {
        cout << y << " ";
      }
      cout << endl;
    }
    return v;
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
  MyTree.levelOrder(root);
  return 0;
}