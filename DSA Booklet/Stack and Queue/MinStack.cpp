#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
class MinStackII
{
public:
    /** initialize your data structure here. */
    vector<int> _stack;
    vector<int> _minStack;
    int minV = -1;
    MinStack()
    {
        _stack.clear();
        _minStack.clear();
    }

    void push(int val)
    {
        _stack.push_back(val);
        if (_minStack.size() > 0)
            _minStack.push_back(min(val, _minStack[_minStack.size() - 1]));
        else
            _minStack.push_back(val);
    }

    void pop()
    {
        if (_stack.size() > 0)
            _stack.pop_back();
        if (_minStack.size() > 0)
            _minStack.pop_back();
    }

    int top()
    {
        if (_stack.size() > 0)
            return _stack[_stack.size() - 1];
        return -1;
    }

    int getMin()
    {
        if (_minStack.size() > 0)
            return _minStack[_minStack.size() - 1];
        return -1;
    }
};

class MinStackIII
{
public:
    /** initialize your data structure here. */
    stack<int> _stack;
    stack<int> _minStack;
    MinStack()
    {
        while (!_stack.empty())
            _stack.pop();
        while (!_minStack.empty())
            _minStack.pop();
    }

    void push(int val)
    {
        _stack.push(val);
        if (_minStack.empty())
        {
            _minStack.push(val);
        }
        else if (val <= _minStack.top())
        {
            _minStack.push(val);
        }
    }

    void pop()
    {
        if (_stack.size() == 0)
            return;
        int topped = _stack.top();
        _stack.pop();
        if (!_minStack.empty() && topped == _minStack.top())
        {
            _minStack.pop();
        }
    }

    int top()
    {
        if (_stack.size() > 0)
            return _stack.top();
        return -1;
    }

    int getMin()
    {
        if (_minStack.size() > 0)
            return _minStack.top();
        return -1;
    }
};

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> _stack;
    int minV = INT_MAX;
    MinStack()
    {
        while (!_stack.empty())
            _stack.pop();
    }

    void push(int x)
    {
        if (_stack.empty())
        {
            _stack.push(x);
            minV = x;
        }
        else if (x <= minV)
        {
            _stack.push(2 * x - minV);
            minV = x;
        }
        else
        {
            _stack.push(x);
        }
    }

    void pop()
    {
        if (_stack.size() == 0)
            return;
        int y = _stack.top();
        if (y <= minV)
        {
            int x = minV;
            minV = 2 * x - y;
        }
        _stack.pop();
    }

    int top()
    {
        if (_stack.size() == 0)
            return -1;
        int y = _stack.top();
        if (y <= minV)
        {
            int x = minV;
            minV = 2 * x - y;
            return x;
        }
        return y;
    }

    int getMin()
    {
        if (_stack.size() == 0)
            return -1;
        return minV;
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        MinStack *obj = new MinStack();
        obj->push(v[0]);
        obj->pop();
        int param_3 = obj->top();
        int param_4 = obj->getMin();
        cout << param_3 << " " << param_4 << endl;
        for (auto x : v)
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