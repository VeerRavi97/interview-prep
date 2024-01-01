#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int dfsHelper(string a, string b, string c, vector<vector<int>> &dp, int i = 0, int j = 0)
{
    if (i == a.length() && j == b.length() && (i + j) == c.length())
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    bool op1 = (i < a.length() && a[i] == c[i + j]) && dfsHelper(a, b, c, dp, i + 1, j);
    // if (op1)
    //     return dp[i][j] = 1;

    bool op2 = (j < b.length() && b[j] == c[i + j]) && dfsHelper(a, b, c, dp, i, j + 1);
    // if (op2)
    //     return dp[i][j] = 1;
    return dp[i][j] = op1 || op2;
}

bool isInterleave(string s1, string s2, string s3)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return dfsHelper(s1, s2, s3, dp);
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
        string a, b, c;
        cin >> a >> b >> c;
        cout << isInterleave(a, b, c) << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}