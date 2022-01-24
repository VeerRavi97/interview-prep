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
int minimumNumberOfCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto coin : coins)
    {
        for (int i = 1; i <= amount; i++)
            if (coin <= i)
            {
                if (dp[i - coin] != INT_MAX && dp[i - coin] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin] + 1;
                }
            }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int totalCoinsDistict(int amount, vector<int> &coins)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto coin : coins)
    {
        for (int i = 1; i <= amount; i++)
            if (coin <= i)
                dp[i] += dp[i - coin];
    }
    return dp[amount];
}

int totalCoinsAllPermutations(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
        for (auto n : nums)
        {
            if (i >= n)
                dp[i] += (dp[i - n] % MOD);
        }
    }
    return dp[target];
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
        int target = 0;
        cin >> target;
        auto ans = minimumNumberOfCoins(v, target);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}