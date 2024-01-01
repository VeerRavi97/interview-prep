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
int firstMissingPositiveII(vector<int> &nums)
{
    sort(all(nums));
    int exp = 1;
    for (auto x : nums)
    {
        if (x == exp)
            exp++;
    }
    return exp;
}

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            nums[i] = 0;
        int idx = nums[i] - 1;
        while (0 <= idx && idx < n && nums[idx] != nums[i])
        {
            swap(nums[i], nums[idx]);
            idx = nums[i] - 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
            return i + 1;
    }
    return n + 1;
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
        auto ans = firstMissingPositive(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}