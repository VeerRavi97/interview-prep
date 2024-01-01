#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(vector<int> &v)
{
    if (v.size() == 0)
        return 0;
    int lh = 0, rh = v.size() - 1;
    int maxleft_so_far = INT_MIN;
    int maxright_so_far = INT_MIN;
    int res = 0;
    while (lh < rh)
    {
        if (v[lh] < v[rh])
        {
            if (v[lh] > maxleft_so_far)
            {
                maxleft_so_far = v[lh];
            }
            else
            {
                res += (maxleft_so_far - v[lh]);
            }
            lh++;
        }
        else
        {
            if (v[rh] > maxright_so_far)
            {
                maxright_so_far = v[rh];
            }
            else
            {
                res += (maxright_so_far - v[rh]);
            }
            rh--;
        }
    }
    return res;
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
        auto ans = solve(v);
        cout << ans << endl;
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}