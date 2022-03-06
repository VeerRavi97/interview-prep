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

void segregate(vvi &intervals, vi &start, vi &end)
{
    for (auto &interval : intervals)
    {
        start.push_back(interval[0]);
        end.push_back(interval[1]);
    }
}

int minMeetingRoomsI(vvi &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return true;
    vector<int> start;
    vector<int> end;
    segregate(intervals, start, end);
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int minRooms = INT_MIN;
    int count = 0;
    int i = 0, j = 0;
    while (i < n && j < n)
    {
        if (start[i] < end[j])
        {
            count += 1;
            i++;
        }
        else
        {
            j++;
            count -= 1;
        }
        minRooms = max(minRooms, count);
    }
    while (i < n)
    {
        count += 1;
        i++;
        minRooms = max(minRooms, count);
    }
    while (j < n)
    {
        count -= 1;
        j++;
        minRooms = max(minRooms, count);
    }
    return minRooms;
}

class comp
{
public:
    bool operator()(const vi &parent, const vi &curr)
    {
        return (parent[1] > curr[1]);
    }
};

int minMeetingRooms(vvi &intervals)
{
    int n = intervals.size();
    if (n == 0)
        return true;
    sort(intervals.begin(), intervals.end());
    priority_queue<vi, vvi, comp> pq;
    int minRooms = INT_MIN;
    int count = 0;
    pq.push(intervals[0]);
    for (int i = 1; i < n; i++)
    {
        if (!pq.empty() && intervals[i][0] >= pq.top()[1])
            pq.pop();
        pq.push(intervals[i]);
    }
    return pq.size();
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
        auto ans = minMeetingRooms(v);
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