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

int recur(vi &cost, vi &dp, int idx)
{
    if (idx <= 1)
        return 0;
    int &ans = dp[idx];
    if (ans == -1)
        return ans;
    int oneStepCost = recur(cost, dp, idx - 1) + cost[idx - 1];
    int twoStepCost = INT_MAX;
    if (idx - 2 >= 0)
        twoStepCost = recur(cost, dp, idx - 2) + cost[idx - 2];
    return ans = min(oneStepCost, twoStepCost);
}

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    return recur(cost, dp, n);
}

int minCostClimbingStairsBU(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int oneStepCost = dp[i - 1] + cost[i - 1];
        int twoStepCost = dp[i - 2] + cost[i - 2];
        dp[i] = min(oneStepCost, twoStepCost);
    }
    return dp[n];
}
int minCostClimbingStairsSpaceOptimized(vector<int> &cost)
{
    int n = cost.size();
    // vector<int> dp(n + 1, 0);
    int secondPrev = 0;
    int prev = 0;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
        int oneStepCost = prev + cost[i - 1];
        int twoStepCost = secondPrev + cost[i - 2];
        curr = min(oneStepCost, twoStepCost);
        secondPrev = prev;
        prev = curr;
    }
    return prev;
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
        auto ans = minCostClimbingStairs(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}