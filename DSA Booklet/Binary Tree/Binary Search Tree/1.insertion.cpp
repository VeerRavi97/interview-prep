#include <bits/stdc++.h>
using namespace std;
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
Node *root = NULL;
// unsigned int allocated = 0;
// Node pool[1000];
// Node *getNode(int data)
// {
//     pool[allocated].data = data;
//     pool[allocated].left = nullptr;
//     pool[allocated].right = nullptr;
//     allocated++;
//     return &pool[allocated - 1];
// }

void insert(int num)
{

    Node *nNode = new Node(num);
    if (root == nullptr)
    {
        cout << "Root is " << nNode->data << endl;
        root = nNode;
        return;
    }

    Node *ptr = root;
    Node *pre = NULL;
    while (ptr)
    {
        pre = ptr;
        if (num < ptr->data)
            ptr = ptr->left;
        else if (num > ptr->data)
            ptr = ptr->right;
    }
    if (num < pre->data)
    {
        // cout << "Inserting " << num << " to left of " << pre->data << endl;
        pre->left = nNode;
    }
    else
    {
        // cout << "Inserting " << num << " to right of " << pre->data << endl;
        pre->right = nNode;
    }
    return;
}

void InOrder(Node *ptr)
{
    if (!ptr)
        return;

    InOrder(ptr->left);
    cout << ptr->data << " ";
    InOrder(ptr->right);
}
void PreOrder(Node *ptr)
{
    if (!ptr)
        return;
    cout << ptr->data << " ";
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

bool search(int num)
{
    Node *ptr = root;
    while (ptr)
    {
        if (ptr->data == num)
            return true;
        else if (ptr->data < num)
            ptr = ptr->right;
        else
            ptr = ptr->left;
    }
    return false;
}
bool searchRec(Node *ptr, int num)
{
    if (!ptr)
    {
        return false;
    }
    if (ptr->data == num)
    {

        return true;
    }
    else if (ptr->data < num)
        return searchRec(ptr->right, num);
    else
        return searchRec(ptr->left, num);
}

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        insert(in);
    }
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    cout << searchRec(root, 15) << endl;
    cout << searchRec(root, 17) << endl;
}