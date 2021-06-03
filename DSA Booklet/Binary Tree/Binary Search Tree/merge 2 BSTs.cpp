#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node *BuildTree(vector<int> &v, int &index)
{
    if (index == v.size())
        return nullptr;
    int curr_ele = v[index++];
    if (curr_ele == -1)
        return nullptr;
    Node *newNode = new Node(curr_ele);
    newNode->left = BuildTree(v, index);
    newNode->right = BuildTree(v, index);
    return newNode;
}
Node *BuildTree(vector<int> &v)
{
    int n = v.size();
    if (n == 0)
        return nullptr;
    int index = 0;
    Node *root = new Node(v[index++]);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (index >= n)
            break;
        int ld = v[index++];
        if (ld != -1)
        {
            Node *leftNode = new Node(ld);
            curr->left = leftNode;
            q.push(leftNode);
        }
        if (index >= n)
            break;
        int rd = v[index++];
        if (rd != -1)
        {
            Node *rightNode = new Node(rd);
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void display(Node *root)
{
    if (!root)
    {
        return;
    }
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

void display(Node *root, vector<int> &v)
{
    if (!root)
    {
        v.push_back(-1);
        return;
    }
    cout << root->data << " ";
    v.push_back(root->data);
    display(root->left, v);
    display(root->right, v);
}

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

void InOrder(Node *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void merge(Node *root1, Node *root2)
{
    stack<Node *> s1;
    Node *current1 = root1;
    stack<Node *> s2;
    Node *current2 = root2;
    if (root1 == NULL)
    {
        InOrder(root2);
        return;
    }
    if (root2 == NULL)
    {
        InOrder(root1);
        return;
    }

    while (current1 != NULL || !s1.empty() ||
           current2 != NULL || !s2.empty())
    {
        if (current1 != NULL || current2 != NULL)
        {
            if (current1 != NULL)
            {
                s1.push(current1);
                current1 = current1->left;
            }
            if (current2 != NULL)
            {
                s2.push(current2);
                current2 = current2->left;
            }
        }
        else
        {
            if (s1.empty())
            {
                while (!s2.empty())
                {
                    current2 = s2.top();
                    s2.pop();
                    current2->left = NULL;
                    InOrder(current2);
                }
                return;
            }
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    current1 = s1.top();
                    s1.pop();
                    current1->left = NULL;
                    InOrder(current1);
                }
                return;
            }
            current1 = s1.top();
            current2 = s2.top();
            if (current1->data < current2->data)
            {
                cout << current1->data << " ";
                s1.pop();
                current1 = current1->right;
                current2 = NULL;
            }
            else
            {
                cout << current2->data << " ";
                s2.pop();
                current2 = current2->right;
                current1 = NULL;
            }
        }
    }
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        Node *root = nullptr;
        int n;
        cin >> n;
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int start_idx = 0;
        root = BuildTree(v);
        vi sv;
        display(root);
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 3
// 15
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 7
// 1 -1 2 -1 3 -1 4
// 6
// 1 2 -1 3 -1 4
