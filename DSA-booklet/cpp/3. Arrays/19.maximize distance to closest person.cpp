#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int maxDistToClosest(vector<int> &seats)
{
    int low = -1, high = 0;
    int maxDist = 0;
    for (high = 0; high < seats.size(); high++)
    {
        int localDist = 0;
        if (seats[high] == 1)
        {
            if (low == -1)
                localDist = high;
            else
                localDist = (high - low) >> 1;
            maxDist = max(maxDist, localDist);
            low = high;
        }
    }
    if (high != low)
        maxDist = max(maxDist, high - low - 1);

    return maxDist;
}
void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = maxDistToClosest(v);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}