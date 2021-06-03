#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
int LCS_Optimized(vector<int> &A, vector<int> &B, vvi &dp)
{
    int bi = 0;
    for (int i = 0; i <= A.size(); i++)
    {
        bi = i & 1;
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
                dp[bi][j] = 0;
            else if (A[i - 1] == B[j - 1])
                dp[bi][j] = 1 + dp[1 - bi][j - 1];
            else
            {
                dp[bi][j] = max(dp[bi][j - 1], dp[1 - bi][j]);
            }
        }
    }
    return dp[bi][B.size()];
}

int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    vvi dp(2, vi(n + 1, 0));
    int ret = LCS_Optimized(A, B, dp);
    return ret;
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
        int m, n;
        cin >> m >> n;
        vi v1(m, 0);
        vi v2(n, 0);
        for (int i = 0; i < m; i++)
            cin >> v1[i];
        for (int i = 0; i < n; i++)
            cin >> v2[i];
        auto ans = maxUncrossedLines(v1, v2);
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