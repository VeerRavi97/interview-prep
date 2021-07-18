#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_CHAR 26

int solve(string text, int k)
{
    int res = 0;
    unordered_map<char, int> mp;
    for (int r = 0, l = 0; r < text.length(); r++)
    {
        mp[text[r]]++;
        while (mp.size() > k)
        {
            mp[text[l]]--;
            if (mp[text[l]] == 0)
            {
                mp.erase(text[l]);
            }
            l++;
        }
        if (mp.size() == k)
        {
            res = max(res, r - l + 1);
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
        string text;
        cin >> text;
        int k;
        cin >> k;
        auto ans = solve(text, k);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}