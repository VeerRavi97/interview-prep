#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;

int mySqrt(int x)
{
    int start = 0;
    int end = x;
    int idx = -1;
    while (start <= end)
    {
        ll mid = start + ((end - start) >> 1);
        ll sqr = mid * mid;
        if (sqr == x)
        {
            idx = mid;
            break;
        }
        else if (sqr < x)
        {
            idx = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return idx;
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
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            cout << mySqrt(x) << endl;
        }
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}