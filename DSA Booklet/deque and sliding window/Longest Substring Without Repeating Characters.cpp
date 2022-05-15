#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mp(256, -1);
        int res = 0;
        for (int l = 0, r = 0; r < s.length(); r++)
        {
            l = max(l, mp[s[r]] + 1);
            res = max(res, r - l + 1);
            mp[s[r]] = r;
        }
        return res;
    }
};

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
        Solution solution;
        auto ans = solution.lengthOfLongestSubstring(str);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}