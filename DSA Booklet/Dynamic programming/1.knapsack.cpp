

#include <iostream>
#include <vector>
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
const unsigned int MAXB = 1e3 + 1;
const unsigned int TOTAL = 1e5 + 1;
int dp[MAXB][TOTAL];

bool isValid(int r, int c)
{
    return (r >= 0 && c >= 0);
}

void dfs(vector<int> &values, vector<int> &weights, int r, int c, int n, vector<int> &path)
{
    // base
    if (r == 0 || c == 0)
    {
        for (auto &x : path)
            cout << x << " ";
        cout << endl;
        return;
    }

    if (dp[r][c] == dp[r - 1][c])
    {
        dfs(values, weights, r - 1, c, n, path);
    }
    else
    {
        //  stringstream ss;
        //   ss << values[r - 1];
        // string temp = "";
        //   ss >> temp;
        // cout << temp << endl;
        int rnbr = r - 1;
        int cnbr = c - weights[r - 1];
        if (isValid(rnbr, cnbr))
        {
            // string temp = std::to_string(r);
            path.push_back(values[r - 1]);
            dfs(values, weights, rnbr, cnbr, n, path);
        }
    }
}
int recur(vector<int> &values, vector<int> &weights, int w, int n, int idx = 0)
{
    if (idx >= n)
    {
        return 0;
    }
    if (dp[idx][w] != -1)
        return dp[idx][w];

    int exclude = recur(values, weights, w, n, idx + 1);
    int include = 0;
    if (w - weights[idx] >= 0)
        include = values[idx] + recur(values, weights, w - weights[idx], n, idx + 1);
    return dp[idx][w] = max(exclude, include);
}

int Maxvalues(vector<int> &values, vector<int> &weights, int W, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            dp[i][j] = -1;
    }
    return recur(values, weights, W, n);
}
int MaxvaluesBU(vector<int> &values, vector<int> &weights, int rem, int n)
{

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= rem; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (j >= weights[i - 1]) //  int c = weights[i - 1]; // current_price
            {
                dp[i][j] = max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    vector<int> path;
    dfs(values, weights, n, rem, n, path);
    return dp[n][rem];
}

int MaxvaluesBUSpaceOptimized(vector<int> &values, vector<int> &weights, int rem, int n)
{
    int dp[2][rem + 1];
    int bi = 0; // binary Index
    for (int i = 0; i <= n; i++)
    {
        bi = i & 1;
        // int p = values[i - 1];
        for (int j = 0; j <= rem; j++)
        {
            if (i == 0 || j == 0)
                dp[bi][j] = 0;
            else if (j >= weights[i - 1]) // int c = weights[i - 1]
            {
                dp[bi][j] = max(dp[1 - bi][j], values[i - 1] + dp[1 - bi][j - weights[i - 1]]);
            }
            else
            {
                dp[bi][j] = dp[1 - bi][j];
            }
        }
    }
    return dp[bi][rem];
}

int MaxvaluesOptimized(vector<int> &values, vector<int> &weights, int W, int n)
{
    int dp[W + 1];
    // memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        int c = weights[i];
        for (int x = W; x >= c; x--)
        {
            dp[x] = max(dp[x], values[i] + dp[x - c]);
        }
    }
    return dp[W];
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    tc = 1;
    while (tc--)
    {
        int n, total;
        cin >> n >> total;
        vector<int> values(n, 0);
        vector<int> weights(n, 0);
        int range = 0;
        for (int i = 0; i < n; i++)
            cin >> weights[i];
        for (int i = 0; i < n; i++)
            cin >> values[i];

        int ans = Maxvalues(values, weights, total, n);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}

// https://cses.fi/problemset/task/1158/