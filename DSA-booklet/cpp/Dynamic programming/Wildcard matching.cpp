#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
public:
    string text;
    string pattern;
    int n1, n2;
    bool recur(vvi &dp, int i = 0, int j = 0)
    {
        if (i == n1 && j == n2)
            return true;
        if (i < n1 && j == n2)
            return false;
        if (i == n1 && j < n2)
        {
            for (int jj = j; jj < n2; jj++)
            {
                if (pattern[jj] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text[i] == pattern[j] || pattern[j] == '?')
        {
            return dp[i][j] = recur(dp, i + 1, j + 1);
        }
        if (pattern[j] == '*')
        {
            bool op1 = recur(dp, i + 1, j); // 0
            bool op2 = recur(dp, i, j + 1);
            return dp[i][j] = op1 || op2;
        }
        return false;
    }
    bool isMatchTD(string s, string p)
    {
        text = s;
        pattern = p;
        n1 = s.length();
        n2 = p.length();
        vvi dp(n1 + 1, vi(n2 + 1, -1));
        return recur(dp);
    }

    bool isMatch(string s, string p)
    {

        text = s;
        pattern = p;
        n1 = s.length();
        n2 = p.length();
        vvi dp(n1 + 1, vi(n2 + 1, 0));
        dp[n1][n2] = 1;

        for (int i = 0; i < n1; i++)
            dp[i][n2] = 0;

        for (int j = 0; j < n2; j++)
        {
            int allStar = 1;
            for (int jj = j; jj < n2; jj++)
            {
                if (pattern[jj] != '*')
                {
                    allStar = 0;
                    break;
                }
            }
            dp[n1][j] = allStar;
        }

        for (int i = n1 - 1; i >= 0; i--)
        {

            for (int j = n2 - 1; j >= 0; j--)
            {
                if (text[i] == pattern[j] || pattern[j] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (pattern[j] == '*')
                {
                    bool op1 = dp[i + 1][j]; // 0
                    bool op2 = dp[i][j + 1];
                    dp[i][j] = op1 || op2;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }
};

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
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
        string text, patt;
        cin >> text >> patt;
        Solution solution;
        auto ans = solution.isMatch(text, patt);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}