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

int EditDistance(string str1, string str2, vvi &dp, int i = 0, int j = 0)
{
    if (i == str1.length())
        return str2.length() - j;
    if (j == str2.length())
        return str1.length() - i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i] == str2[j])
    {
        return dp[i][j] = EditDistance(str1, str2, dp, i + 1, j + 1);
    }
    int op1 = EditDistance(str1, str2, dp, i, j + 1);     // Insert
    int op2 = EditDistance(str1, str2, dp, i + 1, j + 1); // Replace
    int op3 = EditDistance(str1, str2, dp, i + 1, j);     // Delete
    return dp[i][j] = 1 + min(min(op1, op2), op3);
}
int EditDistanceII(string str1, string str2, vvi &dp, int i, int j)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (str1[i - 1] == str2[j - 1])
    {
        return dp[i][j] = EditDistance(str1, str2, dp, i - 1, j - 1);
    }
    int op1 = EditDistance(str1, str2, dp, i, j - 1);     // Insert
    int op2 = EditDistance(str1, str2, dp, i - 1, j - 1); // Replace
    int op3 = EditDistance(str1, str2, dp, i - 1, j);     // Delete
    return dp[i][j] = 1 + min(min(op1, op2), op3);
}

int EditDistance_BU(string str1, string str2, vvi &dp)
{
    int m = str1.length();
    int n = str2.length();

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int op1 = dp[i][j - 1];     // Insert
                int op2 = dp[i - 1][j - 1]; // Replace
                int op3 = dp[i - 1][j];     // Delete
                dp[i][j] = 1 + min(min(op1, op2), op3);
            }
        }
    }

    return dp[m][n];
}

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    vvi dp(m + 1, vi(n + 1, -1));
    return EditDistance_BU(word1, word2, dp);
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
        auto ans = minDistance(s1, s2);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}