#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
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

bool isSubset(vector<int> &nums, int target)
{
    vector<int> possible(target + 1, 0);
    possible[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        for (int j = target; j >= curr; j--)
        {
            possible[j] |= possible[j - curr];
        }
    }
    return possible[target];
}
void subsetSums(vector<int> &v, int n, int range, vector<int> &possible)
{

    possible[0] = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int c = v[i];
        for (int x = range; x >= c; x--)
        {
            if (possible[x - c])
            {
                possible[x] = 1;
            }
        }
    }
}

bool canPartition(vector<int> &nums)
{
    int range = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        range += nums[i];
    }
    if (range & 1)
        return false;
    int ret = isSubset(nums, (range >> 1));
    return (ret) ? true : false;
}

int minDifference(vector<int> &arr, int n)
{
    // Your code goes here
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    int s1, s2;
    vector<int> possible(range + 1, 0);
    subsetSums(arr, n, range, possible);
    for (int i = range / 2; i >= 0; i--)
    {
        if (possible[i])
        {
            s1 = i;
            s2 = range - s1;
            return s2 - s1;
        }
    }
    return 0;
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, range = 0;
        cin >> n;
        vector<int> values(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> values[i];
        }

        int ans = minDifference(values, n);

        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}