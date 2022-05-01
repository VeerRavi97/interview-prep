#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
unsigned const int MOD = 1e9 + 7;

int recur(vector<int> &coins, vector<vector<int>> &dp, int n, int target, int idx = 0)
{
    if (target == 0)
        return 0;
    if (idx == n)
        return 1e9; // Not INT_MAX, 1+INT_MAX: error
    if (dp[idx][target] != -1)
        return dp[idx][target];
    int exclude = recur(coins, dp, n, target, idx + 1);
    int include = 1e9;
    if (coins[idx] <= target)
    {
        include = 1 + recur(coins, dp, n, target - coins[idx], idx);
    }
    return dp[idx][target] = min(exclude, include);
}

int coinChange(vector<int> &coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    int res = recur(coins, dp, n, target);
    return (res == 1e9) ? -1 : res;
}

int minimumNumberOfCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for (auto coin : coins)
    {
        for (int target = 1; target <= amount; target++)
        {
            int exclude = dp[target];
            int include = 1e9;
            if (coin <= target)
            {
                include = 1 + dp[target - coin];
            }
            dp[target] = min(include, exclude);
        }
    }
    return dp[amount] == 1e9 ? -1 : dp[amount];
}
/**
 * Problem URL: https://cses.fi/problemset/task/1636/
 */
ll totalCoinsDistict(vector<ll> &coins, ll amount)
{
    vector<ll> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto coin : coins)
    {
        for (ll i = 1; i <= amount; i++)
            if (coin <= i)
                dp[i] += dp[i - coin] % MOD;
    }
    return dp[amount] % MOD;
}

/**
 * Problem URL:  https://cses.fi/problemset/task/1635/
 */

ll totalCoinsAllPermutations(vector<ll> &nums, ll target)
{
    vector<ll> dp(target + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= target; ++i)
    {
        for (auto n : nums)
        {
            if (i >= n)
                dp[i] += (dp[i - n] % MOD);
        }
    }
    return dp[target] % MOD;
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
    int tc = 1;
    //  cin >> tc;
    while (tc--)
    {
        int n;
        ll target = 0;
        cin >> n;
        cin >> target;
        vector<ll> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        auto ans = totalCoinsDistict(v, target);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}