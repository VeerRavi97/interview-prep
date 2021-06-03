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
void dfs(int r, int c, int len, string s1, string s2, string &path, vvi &dp)
{
    if (r == 0 || c == 0 || len == 0)
        return;
    if (s1[r - 1] == s2[c - 1])
    {
        path.push_back(s1[r - 1]);
        return dfs(r - 1, c - 1, len - 1, s1, s2, path, dp);
    }
    if (dp[r - 1][c] > dp[r][c - 1])
    {
        return dfs(r - 1, c, len, s1, s2, path, dp);
    }
    return dfs(r, c - 1, len, s1, s2, path, dp);
}
int LCS_TD(string s1, string s2, vvi &dp, int s1index = 0, int s2index = 0)
{

    if (s1index == s1.length() || s2index == s2.length())
        return 0;
    if (dp[s1index][s2index] != -1)
        return dp[s1index][s2index];
    if (s1[s1index] == s2[s2index])
        return dp[s1index][s2index] = 1 + LCS_TD(s1, s2, dp, s1index + 1, s2index + 1);
    int op1 = LCS_TD(s1, s2, dp, s1index + 1, s2index);
    int op2 = LCS_TD(s1, s2, dp, s1index, s2index + 1);
    return dp[s1index][s2index] = max(op1, op2);
}

int LCS_BU(string s1, string s2, vvi &dp)
{
    for (int i = 0; i <= s1.length(); i++)
    {
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int LCS_Optimized(string s1, string s2, vvi &dp)
{
    int bi = 0;
    for (int i = 0; i <= s1.length(); i++)
    {
        bi = i & 1;
        for (int j = 0; j <= s2.length(); j++)
        {
            if (i == 0 || j == 0)
                dp[bi][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                dp[bi][j] = 1 + dp[1 - bi][j - 1];
            else
            {
                dp[bi][j] = max(dp[bi][j - 1], dp[1 - bi][j]);
            }
        }
    }
    return dp[bi][s2.length()];
}

int longestCommonSubsequenceII(string text1, string text2)
{
    vvi dp(2, vi(text2.length() + 1, 0));
    int ret = LCS_Optimized(text1, text2, dp);
    return ret;
}
int longestCommonSubsequence(string text1, string text2, string &path)
{
    vvi dp(text1.length() + 1, vi(text2.length() + 1, 0));
    int ret = LCS_BU(text1, text2, dp);
    dfs(text1.length(), text2.length(), ret, text1, text2, path, dp);
    reverse(all(path));
    return ret;
}

string merge(string str1, string str2, string path)
{
    int m = str1.length();
    int n = str2.length();
    int len = path.length();
    int i = 0, j = 0, k = 0;
    string merged;
    while (i < m && j < n && k < len)
    {
        if (path[k] == str1[i] && path[k] == str2[j])
        {
            merged.push_back(path[k]);
            k++;
            i++;
            j++;
        }
        else if (path[k] != str1[i])
        {
            merged.push_back(str1[i]);
            i++;
        }
        else if (path[k] != str2[j])
        {
            merged.push_back(str2[j]);
            j++;
        }
    }
    while (i < m)
    {
        merged.push_back(str1[i++]);
    }
    while (j < n)
    {
        merged.push_back(str2[j++]);
    }
    return merged;
}

string shortestCommonSupersequence(string str1, string str2)
{
    string path;
    longestCommonSubsequence(str1, str2, path);
    // cout << path << endl;
    string scs;
    scs = merge(str1, str2, path);
    return scs;
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
        auto ans = shortestCommonSupersequence(s1, s2);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}