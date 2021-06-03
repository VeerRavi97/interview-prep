#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> pii;
typedef vector<vector<int>> vvi;

class node
{
public:
  int ele;
  int kth;
  int ith;
  node(int eleX, int kthX, int ithX)
  {
    ele = eleX;
    kth = kthX;
    ith = ithX;
  }
};
class comp
{
public:
  bool operator()(node a, node b)
  {
    return b.ele < a.ele;
  }
};
void file_io()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
}

void merge(vvi &m)
{
  vector<int> res;
  priority_queue<node, vector<node>, comp> pq; // min heap
  for (int i = 0; i < m.size(); i++)
  {
    node newnode(m[i][0], i, 0);
    pq.push(newnode);
  }

  while (!pq.empty())
  {
    node curr = pq.top();
    pq.pop();
    // cout << "minimum element :" << curr.ele << "\n";
    res.push_back(curr.ele);
    int kth = curr.kth;
    int ith = curr.ith;
    if (ith + 1 < m[kth].size())
    {
      node newNode(m[kth][ith + 1], kth, ith + 1);
      pq.push(newNode);
    }
  }
  for (auto x : res)
  {
    cout << x << " ";
  }
}

int main()
{
  file_io();
  int k;
  cin >> k;
  vvi m(k);
  for (int i = 0; i < k; i++)
  {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
      int in;
      cin >> in;
      m[i].push_back(in);
    }
  }
  for (int i = 0; i < m.size(); i++)
  {
    for (int j = 0; j < m[i].size(); j++)
      cout << m[i][j] << " ";
    cout << "\n";
  }
  merge(m);

  return 0;
}