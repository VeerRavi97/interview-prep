#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool comp(const vi &a, const vi &b)
{
    return (a[1] < b[1]);
}

int maxEvents(vector<vector<int>> &events)
{
    int n = events.size();
    if (n == 0)
        return true;
    sort(events.begin(), events.end(), comp);
    int maxEvents = 1;
    vi runningEvent = events[0];
    for (int i = 1; i < n; i++)
    {
        if (events[i][0] >= runningEvent[1])
        {
            maxEvents += 1;
            runningEvent = events[i];
        }
        else
        {
            runningEvent[1] = max(runningEvent[1], events[i][1]);
        }
    }
    return maxEvents;
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
        vector<vector<int>> v(n, vector<int>(2));
        for (int i = 0; i < n; i++)
            cin >> v[i][0] >> v[i][1];
        auto ans = maxEvents(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}

/*

1
3
0 30 
5 10
15 20


*/