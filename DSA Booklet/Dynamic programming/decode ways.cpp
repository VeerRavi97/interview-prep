#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int numDecodings(string s)
{
    int len = s.length();
    vector<int> dp(len + 1, 0);
    if (s[0] == '0')
        return 0;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= len; i++)
    {
        dp[i] = 0;
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        int num = s[i - 2] - '0';
        num = num * 10 + (s[i - 1] - '0');
        if (num >= 10 && num <= 26)
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[len];
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
        string str;
        cin >> str;
        auto ans = numDecodings(str);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}

// 5
// 2611055971756562
// 12
// 226
// 0
// 100

// 4
// 2
// 3
// 0
// 0