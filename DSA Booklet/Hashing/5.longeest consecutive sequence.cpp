#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

int longestConsecutive(vector<int> &nums)
{
    int res = INT_MIN;
    unordered_set<int> s;
    for (auto ele : nums)
        s.insert(ele);
    for (auto ele : nums)
    {
        int prev = ele - 1;
        if (s.count(prev))
            continue;
        int cnt = 1;
        int next = ele + 1;
        while (s.find(next) != s.end())
        {
            cnt++;
            next++;
        }
        res = max(res, cnt);
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
        int n;
        cin >> n;
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = longestConsecutive(v);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}