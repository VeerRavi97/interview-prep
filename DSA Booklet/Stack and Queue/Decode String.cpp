#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

string decodeString(string str)
{
    string res = "";
    stack<int> s1;
    stack<string> s2;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (isDigit(ch))
        {
            int num = 0;
            while (i < str.length() && isDigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--;
            s1.push(num);
        }
        else if (ch == '[')
        {
            s2.push(res);
            res = "";
        }
        else if (ch == ']')
        {
            int cnt = (!s1.empty() ? s1.top() : 0);
            if (!s1.empty())
                s1.pop();
            string tp = (!s2.empty() ? s2.top() : "");
            if (!s2.empty())
                s2.pop();
            for (int j = 0; j < cnt; j++)
            {
                tp += res;
            }
            res = tp;
        }
        else
        {
            res += ch;
        }
    }
    return res;
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
        auto ans = decodeString(str);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}