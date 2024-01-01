#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int superEggDropHelper(int e, int f, vvi &dp)
{
    if (e == 1 || f == 1 || f == 0)
        return dp[f][e] = f;

    if (dp[f][e] != -1)
        return dp[f][e];
    int minAttemps = INT_MAX;
    for (int i = 1; i <= f; i++)
    {
        int op1 = superEggDropHelper(e - 1, i - 1, dp);
        int op2 = superEggDropHelper(e, f - i, dp);
        minAttemps = min(minAttemps, (max(op1, op2) + 1));
    }
    return dp[f][e] = minAttemps;
}
int superEggDrop(int e, int f)
{
    vvi dp(f + 1, vi(e + 1, -1));
    return superEggDropHelper(e, f, dp);
}

int superEggDropBU(int e, int f)
{
    vvi dp(f + 1, vi(e + 1, 0));
    for (int i = 1; i <= f; i++)
    {
        dp[i][1] = i;
    }
    for (int j = 1; j <= e; j++)
    {
        dp[1][j] = 1;
    }
    int minAttemps = INT_MAX;

    for (int i = 2; i <= f; i++)
    {
        for (int j = 2; j <= e; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= i; k++)
            {
                int attempts = 1 + max(dp[k - 1][j - 1], dp[i - k][j]);
                dp[i][j] = min(dp[i][j], attempts);
            }
        }
    }
    return dp[f][e];
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
        int k, n;
        cin >> k >> n;
        auto ans = superEggDropBU(k, n);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}