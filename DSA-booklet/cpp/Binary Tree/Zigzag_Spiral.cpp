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

void zig_zagI(Node *root)
{
}
void zig_zagII(Node *root)
{
}
void zig_zagIII(Node *root)
{
}
void zig_zagIV(Node *root, vector<int> &zv)
{
    if (!root)
        return;
    deque<Node *> dq;
    dq.push_back(root);
    int ltr = 0;
    while (!dq.empty())
    {
        int count = dq.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr;
            if (ltr == 1)
            {
                curr = dq.back();
                dq.pop_back();
                zv.push_back(curr->data);
                if (curr->left)
                    dq.push_front(curr->left);
                if (curr->right)
                    dq.push_front(curr->right);
            }
            else
            {
                curr = dq.front();
                dq.pop_front();
                zv.push_back(curr->data);
                if (curr->right)
                    dq.push_back(curr->right);
                if (curr->left)
                    dq.push_back(curr->left);
            }
        }
        ltr = !ltr;
    }
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
        root = BuildTree(v, start_idx);
        vi sv; // serialized vector
        display(root, sv);
        cout << endl;
        vi zv;
        zig_zagIV(root, zv);
        for (auto x : zv)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
// 31
// 1 2 4 8 -1 -1 9 -1 -1 5 10 -1 -1 11 -1 -1 3 6 12 -1 -1 13 -1 -1 7 14 -1 -1 15 -1 -1