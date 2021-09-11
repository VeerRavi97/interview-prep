#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

string isPaindromeHelper(string s)
{
    string res = "";
    for (auto ch : s)
    {
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        {
            res += ch;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - 'A' + 'a';
            res += ch;
        }
    }
    return res;
}

bool isPaindrome(string s)
{
    s = isPaindromeHelper(s);
    cout << s << endl;
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
            return 0;
        start++;
        end--;
    }
    return 1;
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
    cin.ignore();
    while (tc--)
    {
        string s, t;
        getline(cin, s);
        auto ans = isPaindrome(s);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}