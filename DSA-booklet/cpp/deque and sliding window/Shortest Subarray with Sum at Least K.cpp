#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(vector<int> &v, int target)
{
    int n = v.size();
    int res = INT_MAX;
    deque<int> dq;
    vector<int> prefix(n + 1, 0);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int prev_idx = i - 1;
        prefix[i] = prefix[prev_idx] + v[prev_idx];
    }
    for (int i = 0; i <= n; i++)
    {
        while (!dq.empty() && (prefix[i] - target) >= prefix[dq.front()])
        {
            res = min(res, i - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefix[i] <= prefix[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    return (res != INT_MAX) ? res : -1;
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
        int target = 0;
        cin >> target;
        auto ans = solve(v, target);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}