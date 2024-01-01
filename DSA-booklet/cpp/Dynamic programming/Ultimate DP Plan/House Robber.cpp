#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(n + 1, 0);
    dp[0] = nums[0];
    int incl = nums[0];
    dp[1] = max(nums[0], nums[1]);
    int excl = 0;
    int res = max(incl, excl);
    for (int i = 1; i < n; i++)
    {
        // dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        res = max(incl, excl + nums[i]);
        excl = incl;
        incl = res;
    }
    return res;
    // return dp[n - 1];
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
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = rob(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}