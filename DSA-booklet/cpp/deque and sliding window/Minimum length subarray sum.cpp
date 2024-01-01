#include <iostream>
#include <algorithm>
#include <vector>
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
    int res = INT_MAX;
    int sum = 0;
    int l = 0, r = 0;
    while (r < v.size())
    {
        sum += v[r];
        //  cout <<  sum << endl;
        while (sum >= target)
        {
            sum -= v[l];
            res = min(res, (r - l + 1));
            l++;
        }
        r++;
    }

    return (res != INT_MAX) ? res : 0;
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
        auto ans = solve(v, target);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}