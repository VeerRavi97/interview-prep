#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(vector<int> &v)
{
    int n = v.size();
    stack<int> _stack;
    for (int i = 0; i < n; i++)
    {
        int span;
        while (!_stack.empty() && v[_stack.top()] <= v[i])
            _stack.pop();
        span = (!_stack.empty()) ? i - _stack.top() : i + 1;
        _stack.push(i);
        cout << span << " ";
    }
    cout << endl;
    return 0;
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
        int n;
        cin >> n;
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = solve(v);
        // cout << ans << endl;
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}