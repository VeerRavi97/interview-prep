#include <iostream>
#include <vector>
#include <deque>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<long long> vi;
typedef vector<vi> vvi;

int solve(vector<long long> &v, long long n, long long k)
{
    vector<long long> res;
    deque<long long> dq;
    for (long long r = 0; r < k; r++)
    {
        if (v[r] < 0)
            dq.push_back(r);
    }
    if (dq.size() > 0)
        res.push_back(v[dq.front()]);
    else
        res.push_back(0);
    for (long long r = k; r < n; r++)
    {
        long long l = r - k + 1;
        if (v[r] < 0)
            dq.push_back(r);
        while (!dq.empty() && dq.front() < l)
        {
            dq.pop_front();
        }
        if (dq.size() > 0)
            res.push_back(v[dq.front()]);
        else
            res.push_back(0);
    }
    for (auto x : res)
        cout << x << " ";
    return 0;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    auto in = freopen("input.txt", "r", stdin);
    auto op = freopen("output.txt", "w", stdout);
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
        int k;
        cin >> k;
        auto ans = solve(v, n, k);
        // cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}