#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_N 1011
void dfs(int r, int c, int len, string s1, string s2, string &path, vvi &dp)
{
    if (r == 0 || c == 0 || len == 0)
        return;
    if (s1[r - 1] == s2[c - 1])
    {
        path.push_back(s1[r - 1]);
        dfs(r - 1, c - 1, len - 1, s1, s2, path, dp);
    }
}
int LCS_TD(string s1, string s2, vvi &dp, int &ans, int s1index, int s2index)
{

    if (s1index == 0 || s2index == 0)
        return 0;
    if (dp[s1index][s2index] != -1)
        return dp[s1index][s2index];
    if (s1[s1index - 1] == s2[s2index - 1])
    {
        dp[s1index][s2index] = 1 + LCS_TD(s1, s2, dp, ans, s1index - 1, s2index - 1);
        ans = max(ans, dp[s1index][s2index]);
    }
    else
    {
        dp[s1index][s2index] = 0;
    }
    //ans = max(ans, lcs_count);
    LCS_TD(s1, s2, dp, ans, s1index - 1, s2index);
    LCS_TD(s1, s2, dp, ans, s1index, s2index - 1);
    return dp[s1index][s2index];
}

int LCS_BU(string s1, string s2, vvi &dp, int &row, int &col)
{
    int ans = 0;
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    row = i;
                    col = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int LCS_Optimized(string s1, string s2, vvi &dp, int &row, int &col)
{
    int bi = 0;
    int ans = 0;
    for (int i = 0; i <= s1.length(); i++)
    {
        bi = i & 1;
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[bi][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[bi][j] = 1 + dp[1 - bi][j - 1];
                if (dp[bi][j] > ans)
                {
                    ans = dp[bi][j];
                    row = i;
                    col = j;
                }
            }
            else
            {
                dp[bi][j] = 0;
            }
        }
    }
    return ans;
}

int LCS_BU_DUP(string s1, string s2, vvi &dp, int &row, int &col)
{
    int ans = 0;
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (i != j && s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                if (dp[i][j] > ans)
                {
                    ans = dp[i][j];
                    row = i;
                    col = j;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int longestCommonSubstring(string text1, string text2, string &path)
{
    vvi dp(text1.length() + 1, vi(text2.length() + 1, -1));
    int ans = 0;
    int ret = LCS_TD(text1, text2, dp, ans, text1.length(), text2.length());
    return ans;
}
int longestCommonSubstringII(string text1, string text2, string &path)
{
    //vvi dp(2, vi(text2.length() + 1, 0));
    vvi dp(text1.length() + 1, vi(text2.length() + 1, 0));
    //int ret = LCS_Optimized(text1, text2, dp);
    int row = 0;
    int col = 0;
    int ret = LCS_BU(text1, text2, dp, row, col);
    dfs(row, col, ret, text1, text2, path, dp);
    reverse(all(path));
    return ret;
}

int longestDupSubstring(string s, string &res)
{
    string ans;
    string _s = s;
    reverse(all(_s));
    return longestCommonSubstringII(s, _s, ans);
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
        string path = "";
        auto ans = longestDupSubstring(s1, path);
        cout << ans << " " << path << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}