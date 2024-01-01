#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
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

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void display(ListNode *head)
{
    while (head)
    {

        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution
{
public:
    void split(ListNode *head, ListNode **a, ListNode **b)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        *b = slow->next;
        slow->next = NULL;
        *a = head;
    }
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr;
        ListNode *next;
        ListNode *curr = head;
        while (curr)
        {
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
    ListNode *mergeAlternative(ListNode *h1, ListNode *h2)
    {
        ListNode *res = h1;
        while (h1 && h2)
        {
            res = h1;
            h1 = h1->next;
            res->next = h2;

            res = h2;
            h2 = h2->next;
            res->next = h1;
        }
        return res;
    }
    void reorderList(ListNode *head)
    {
        if (!head || !head->next)
            return;
        ListNode *a, *b = nullptr;
        split(head, &a, &b);
        b = reverse(b);
        head = mergeAlternative(a, b);
    }
};

ListNode *insert(ListNode *head, int ele)
{
    ListNode *newNode = new ListNode(ele);
    newNode->next = head;
    head = newNode;
    return head;
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        ListNode *head = nullptr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            head = insert(head, ele);
        }
        Solution Obj;
        Obj.reorderList(head);
        display(head);
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}