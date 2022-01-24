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
int kEmptySlots(vector<int> &bulbs, int k)
{
    int start = 1;           // window start
    int end = start + k + 1; // window end
    int n = bulbs.size();
    vector<int> pos(n + 1, 0);
    int ans = INT_MAX;
    for (int idx = 0; idx < n; idx++)
        pos[bulbs[idx]] = idx + 1;
    for (int i = 1; end <= n; i++)
    {
        if (i < end && pos[i] >= pos[start] && pos[i] >= pos[end])
            continue;
        if (i == end)
            ans = min(ans, max(pos[start], pos[end]));
        start = i;
        end = start + k + 1;
    }
    return ans == INT_MAX ? -1 : ans;
}
int kEmptySlotsII(vector<int> &bulbs, int K)
{
    int n = bulbs.size();
    int position[n + 1];
    for (int i = 0; i < n; i++)
        position[bulbs[i]] = i + 1;
    int result = INT_MAX;
    int start = 1, end = K + 2;
    for (int i = 1; end <= n; i++)
    {
        if (position[i] > position[start] && position[i] > position[end])
            continue;
        if (i == end)
            result = min(result, max(position[start], position[end]));
        start = i;
        end = i + K + 1;
    }
    return result == INT_MAX ? -1 : result;
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
        int n, k;
        cin >> n >> k;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = kEmptySlots(v, k);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}