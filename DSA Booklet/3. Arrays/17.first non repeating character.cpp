#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(string s)
{
    int n = s.length();
    vector<int> firstOccurrences(26, -1);
    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'a';
        if (firstOccurrences[idx] == -1) // occurred first time
            firstOccurrences[idx] = i;
        else
        {
            firstOccurrences[idx] = -2;
        }
    }
    int minV = 9999999;
    bool found = false;
    for (int i = 0; i < 26; i++)
    {
        if (firstOccurrences[i] >= 0)
        {
            found = true;
            minV = min(minV, firstOccurrences[i]);
        }
    }
    return (found ? minV : -1);
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
        string s;
        cin >> s;
        auto ans = solve(s);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}