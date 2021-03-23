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

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    int index = 0;
    while (!s1.empty() && index < n)
    {
        s2.push(s1.top());
        s1.pop();
        index++;
    }
}
// Using two stacks
void reverseNaive(stack<int> &s1, int n)
{
    stack<int> s2;
    stack<int> s3;
    transfer(s1, s2, n);
    transfer(s2, s3, n);
    transfer(s3, s1, n);
}
// Using one stack
void reverseBetter(stack<int> &s1, int n)
{
    stack<int> s2;
    for (int i = 0; i < n; i++)
    {
        int topped = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(topped);
        transfer(s2, s1, n - i - 1);
    }
}
void insertAtBottom(stack<int> &s, int n, int ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }
    int popped = s.top();
    s.pop();
    insertAtBottom(s, n, ele);
    s.push(popped);
}

void reverseRec(stack<int> &s, int n)
{
    if (s.empty())
        return;
    int topped = s.top();
    s.pop();
    reverseRec(s, n);
    insertAtBottom(s, n, topped);
}

void display(stack<int> &s1)
{
    while (!s1.empty())
    {
        int x = s1.top();
        cout << x << " ";
        s1.pop();
    }
    cout << "\n";
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
        stack<int> s1;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            s1.push(in);
        }
        // reverseNaive(s1, n);
        // reverseBetter(s1, n);
        reverseRec(s1, n);
        display(s1);
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}
