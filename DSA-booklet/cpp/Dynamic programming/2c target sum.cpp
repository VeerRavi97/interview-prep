#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
#define ll long long
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
const unsigned int MOD = 1e9 + 7;
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

int isSubsetRecur(vector<int> &v, vector<vector<int>> &dp, int idx, int sum, int target, int &total)
{
    if (idx == v.size())
        return (sum == target);

    if (dp[idx][sum + total] != -1)
        return dp[idx][sum + total];
    int add = isSubsetRecur(v, dp, idx + 1, sum + v[idx], target, total);
    int substract = isSubsetRecur(v, dp, idx + 1, sum - v[idx], target, total);
    return dp[idx][sum + total] = (add + substract);
}
int isSubsetSumTD(vector<int> &nums, int target)
{
    int total = 0;
    int n = nums.size();
    for (auto &x : nums)
        total += x;
    vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));
    return isSubsetRecur(nums, dp, 0, 0, target, total);
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> v;
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
            range += in;
        }
        // subsetSums(v, n, range);
        int cnt = isSubsetSumTD(v, target);
        cout << cnt << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}