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

void findRange(vector<int> &nums, int &start, int &end)
{
    for (int &x : nums)
    {
        start = max(start, x);
        end += x;
    }
}

bool isValid(vector<int> &nums, int m, int ans)
{
    int k = 1;
    int sum = 0;
    for (int &x : nums) // 7 2 5 10 8, mid = 21
    {
        if (sum + x > ans)
        {
            k++;
            if (k > m)
                return false;
            sum = x;
        }
        else
        {
            sum += x;
        }
    }
    return true;
}

int splitArray(vector<int> &nums, int m)
{
    int start = 0;
    int end = 0;
    findRange(nums, start, end);
    int total = end;
    int res = -1;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (isValid(nums, m, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return res;
    // return (res == -1 ? -1 : total - res);
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
        int n, m;
        cin >> n >> m;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = splitArray(v, m);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}