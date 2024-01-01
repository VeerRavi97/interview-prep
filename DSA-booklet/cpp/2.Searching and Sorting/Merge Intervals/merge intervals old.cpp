#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vector<vector<int>> mergeII(vector<vector<int>> &intervals)
{
    vvi res;
    int n = intervals.size();
    sort(all(intervals));
    vi itr(2, 0);
    itr[0] = intervals[0][0];
    itr[1] = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (itr[1] >= intervals[i][0])
        {
            itr[1] = max(intervals[i][1], itr[1]);
        }
        else
        {
            res.push_back(itr);
            itr = intervals[i];
        }
    }
    res.push_back(itr);
    return res;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vvi res;
    int n = intervals.size();
    if (n == 0)
        return res;
    sort(all(intervals));
    res.push_back(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        int x2 = intervals[i][0];
        int y2 = intervals[i][1];
        int x1 = res[res.size() - 1][0];
        int y1 = res[res.size() - 1][1];
        if (y1 >= x2)
        {
            res[res.size() - 1][1] = max(y1, y2);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }
    return res;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    auto ip = freopen("input.txt", "r", stdin);
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
        vvi v(n, vi(2, 0));
        for (int i = 0; i < n; i++)
        {
            int f, s;
            cin >> f >> s;
            v[i][0] = f;
            v[i][1] = s;
        }
        auto ans = merge(v);
        for (auto v : ans)
        {
            for (auto x : v)
                cout << x << " ";
            cout << endl;
        }
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}