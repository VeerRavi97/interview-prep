#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int longestValidParenthesesII(string str)
{
    stack<int> s;
    s.push(-1);
    int res = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            s.push(i);
        else
        {
            if (!s.empty() && s.top() != -1 && str[s.top()] == '(')
            {
                s.pop();
                res = max(res, i - s.top());
            }
            else
            {
                s.push(i);
            }
        }
    }
    return res;
}

int longestValidParentheses(string str)
{
    int res = 0;
    int lp = 0, rp = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            lp++;
        else
            rp++;
        if (lp == rp)
            res = max(res, lp + rp);
        else if (rp > lp)
            lp = rp = 0;
    }
    lp = rp = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
            lp++;
        else
            rp++;
        if (lp == rp)
            res = max(res, lp + rp);
        else if (lp > rp)
            lp = rp = 0;
    }
    return res;
}

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
        string str;
        cin >> str;
        auto ans = longestValidParentheses(str);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}