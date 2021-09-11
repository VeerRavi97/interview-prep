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

bool isPaindromeHelper(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return 0;
        start++;
        end--;
    }
    return 1;
}

bool isPaindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return (isPaindromeHelper(s, start + 1, end)) || (isPaindromeHelper(s, start, end - 1));
        }
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
    while (tc--)
    {
        string s;
        cin >> s;
        auto ans = isPaindrome(s);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}