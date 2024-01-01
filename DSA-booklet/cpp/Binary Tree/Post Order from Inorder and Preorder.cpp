#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
int preindex = 0;
int cnt = 0;
unordered_map<int, int> mp;
class Node
{
public:
  int data;
  Node *left, *right;
  Node(int d)
  {
    data = d;
    left = right = nullptr;
  }
};

class Solution
{
public:
  Node *buildtree(vector<int> &in, vector<int> &pre, int start, int end)
  {

    if (end < start)
      return NULL;
    int num = pre[preindex++];
    int pos = mp[num];
    //  cout << "creating node " << num << " " << pos << "\n";
    Node *nn = new Node(num);
    nn->left = buildtree(in, pre, start, pos - 1);
    nn->right = buildtree(in, pre, pos + 1, end);
    return nn;
  }

  void postorder(Node *root)
  {
    if (root)
    {
      postorder(root->left);
      postorder(root->right);
      cout << root->data << " ";
    }
  }
};
int main()
{
  int n;
  cin >> n;
  vector<int> pre;
  vector<int> in;
  for (int i = 0; i < n; i++)
  {
    int inp;
    cin >> inp;
    in.push_back(inp);
    mp[inp] = i;
  }
  for (int i = 0; i < n; i++)
  {
    int inp;
    cin >> inp;
    pre.push_back(inp);
  }

  Solution MyTree;
  Node *root = MyTree.buildtree(in, pre, 0, n - 1);
  MyTree.postorder(root);
}