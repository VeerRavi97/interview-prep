#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 5;
unordered_map<int, int> mp;
int postindex = 0;
int cnt = 0;
class Node
{
public:
    int data;
    Node *left, *right = nullptr;
    Node(int node_data)
    {
        this->data = node_data;
        this->left = this->right = nullptr;
    }
};
class Solution
{
public:
    Node *buildtree(vector<int> &in, vector<int> &post, int start, int end)
    {

        //   cout << start << " " << end << " " << "postindex " <<  postindex << "\n";
        if (start > end)
            return NULL;
        int num = post[postindex--];
        int pos = mp[num];
        Node *nn = new Node(num);
        nn->right = buildtree(in, post, pos + 1, end);
        nn->left = buildtree(in, post, start, pos - 1);
        return nn;
    }
    void preorder(Node *root)
    {
        if (root)
        {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution MyTree;
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> post(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        in[i] = x;
        mp[x] = i;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        post[i] = x;
    }
    postindex = n - 1;
    Node *root = MyTree.buildtree(in, post, 0, n - 1);
    MyTree.preorder(root);

    return 0;
}