#include <iostream>
#include <queue>
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
Node *getSuccessor(Node *root)
{
    if (!root)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}

Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else if (key == root->data)
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (root->left && !root->right)
        {
            Node *leftNode = root->left;
            delete root;
            return leftNode;
        }
        else if (root->right && !root->left)
        {
            Node *rightNode = root->right;
            delete root;
            return rightNode;
        }
        else
        {
            Node *successor = getSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
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
        int n, key;
        cin >> n >> key;
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int start_idx = 0;
        root = BuildTree(v);
        vi sv;
        display(root);
        cout << endl;
        root = deleteNode(root, key);
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
