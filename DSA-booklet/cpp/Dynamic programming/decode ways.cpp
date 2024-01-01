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

int recur(string &s, int idx, vector<int> &dp)
{

    if (idx >= s.length())
        return 1;
    if (s[idx] == '0')
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    if (idx == s.length() - 1)
        return 1;
    int oneDigitNum = s[idx] - '0';
    int op1 = 0, op2 = 0;
    if (oneDigitNum != 0)
        op1 = recur(s, idx + 1, dp);
    int twoDigitNum = s[idx + 1] - '0';
    twoDigitNum = oneDigitNum * 10 + twoDigitNum;
    if (twoDigitNum >= 10 && twoDigitNum <= 26)
    {
        op2 = recur(s, idx + 2, dp);
    }

    return dp[idx] = op1 + op2;
}
int numDecodings(string s)
{
    int len = s.length();
    vector<int> dp(len, -1);
    return recur(s, 0, dp);
}
class Solution
{
public:
    int numDecodingsII(string s)
    {
        int len = s.length();
        // vector<int>dp(len+1, 0);
        if (s[0] == '0')
            return 0;
        int twoDigitBack = 1; // dp[0] = 1;
        int oneDigitBack = 1; // dp[1] = 1;
        int currDigit;
        for (int i = 1; i < len; i++)
        {
            currDigit = 0;
            int oneDigitNum = s[i] - '0';
            if (oneDigitNum != 0)
                currDigit += oneDigitBack;
            int twoDigitNum = s[i - 1] - '0';
            twoDigitNum = twoDigitNum * 10 + oneDigitNum;
            if (twoDigitNum >= 10 && twoDigitNum <= 26)
            {
                currDigit += twoDigitBack;
            }

            twoDigitBack = oneDigitBack;
            oneDigitBack = currDigit;
        }
        return oneDigitBack;
    }
    int numDecodings(string s)
    {
        int len = s.length();
        vector<int> dp(len + 1, 0);
        if (s[0] == '0')
            return 0;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < len; i++)
        {
            dp[i + 1] = 0;
            int oneDigitNum = s[i] - '0';
            if (oneDigitNum != 0)
                dp[i + 1] += dp[i];
            int twoDigitNum = s[i - 1] - '0';
            twoDigitNum = twoDigitNum * 10 + oneDigitNum;
            if (twoDigitNum >= 10 && twoDigitNum <= 26)
            {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[len];
    }
};

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