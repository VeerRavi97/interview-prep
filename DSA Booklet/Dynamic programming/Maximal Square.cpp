#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<char> vi;
typedef vector<vi> vvi;

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m == 0 || matrix[0].size() == 0)
        return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int max_so_far = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = matrix[i][j] - '0';
            if (i > 0 && j > 0 && dp[i][j])
            {
                dp[i][j] += min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
            }
            max_so_far = max(max_so_far, dp[i][j]);
        }
    }
    return max_so_far * max_so_far;
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
        vvi v(m, vi(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        auto ans = maximalRectangle(v);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}