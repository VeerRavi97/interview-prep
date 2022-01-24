#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
bool canAttendMeetings(vector<vector<int>> &intervals)
{

    int n = intervals.size();
    if (n == 0)
        return true;
    sort(intervals.begin(), intervals.end());
    vector<int> runningInterval = intervals[0];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] >= runningInterval[1])
        {
            runningInterval = intervals[i];
        }
        else
        {
            return false;
        }
    }
    return true;
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
        auto ans = canAttendMeetings(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}