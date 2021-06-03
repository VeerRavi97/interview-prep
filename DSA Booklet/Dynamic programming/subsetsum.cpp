#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
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

int subsetSums(vector<int> &v, int n, int range)
{
    vector<int> possible(range + 1, 0);
    possible[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int c = v[i];
        for (int x = range; x >= c; x--)
        {
            if (possible[x - c])
            {
                possible[x] = 1;
            }
        }
    }
    for (int i = 1; i <= range; i++)
    {
        if (possible[i])
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= range; i++)
    {
        if (possible[i])
            cout << i << " ";
    }
    cout << endl;

    return 1;
}
bool isValid(int r, int c)
{
    return (r >= 0 && c >= 0);
}
void dfs(vector<vector<int>> &dp, vector<int> &v, int r, int c, string path)
{
    if (r == 0 || c == 0)
    {
        cout << path << endl;
        return;
    }

    if (dp[r - 1][c] > 0)
    {
        int rnbr = r - 1;
        int cnbr = c;
        if (isValid(rnbr, cnbr))
            dfs(dp, v, rnbr, cnbr, path);
    }
    stringstream ss;
    ss << v[r - 1];
    string temp = "";
    ss >> temp;
    int rnbr = r - 1;
    int cnbr = c - v[r - 1];
    if (isValid(rnbr, cnbr) && dp[rnbr][cnbr] > 0)
        dfs(dp, v, rnbr, cnbr, path + temp);
}

int isSubsetSum(vector<int> &v, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    // memset(dp, 0, sizeof(dp));
    for (int j = 0; j <= target; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int curr = v[i - 1];
        for (int j = 1; j <= target; j++)
        {
            if (j < curr)
                dp[i][j] = dp[i - 1][j];
            else if (j - curr >= 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - curr];
        }
    }
    string path = " ";
    dfs(dp, v, n, target, path);
    return dp[n][target];
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    tc = 3;
    while (tc--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> v;
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
            range += in;
        }
        //subsetSums(v, n, range);
        int cnt = isSubsetSum(v, n, target);
        cout << cnt << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}