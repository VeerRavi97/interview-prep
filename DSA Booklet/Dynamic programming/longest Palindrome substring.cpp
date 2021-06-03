#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_N 1011

int LPS_BU(string s, vvi &dp, int &sIdx)
{
    int max_length = 1;
    for (int len = 1; len <= s.length(); len++)
    {

        for (int i = 0; i + len - 1 < s.length(); i++)
        {
            int j = i + len - 1;

            if (len == 1)
                dp[i][j] = 1;
            else if (len == 2 && s[i] == s[j])
            {
                dp[i][j] = 1;
                max_length = len;
                sIdx = i;
            }
            else if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = 1;
                max_length = len;
                sIdx = i;
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return max_length;
}

int longestPalindromeSubstring(string text, string &res)
{
    //vvi dp(2, vi(text.length() + 1, 0));
    vvi dp(text.length() + 1, vi(text.length() + 1, 0));

    int sIdx = 0;
    int ret = LPS_BU(text, dp, sIdx);
    res = text.substr(sIdx, ret);
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

        string s1, s2;
        cin >> s1 >> s2;
        string res = "";
        auto ans = longestPalindromeSubstring(s1, res);
        cout << ans << " " << res << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}