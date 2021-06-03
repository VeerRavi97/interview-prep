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
int maxProfitI(vector<int> &prices) // 1 transaction allowed
{
    if (prices.size() < 2)
        return 0;
    int cheapest = prices[0];
    int res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        res = max(res, prices[i] - cheapest);
        cheapest = min(cheapest, prices[i]);
    }
    return res;
}
int maxProfitII(vector<int> &prices) // unlimited transactions
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += (prices[i] - prices[i - 1]);
        }
    }
    return profit;
}
int maxProfitIII(vector<int> &prices) // 2 transactions
{
    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;
    int money = 0;
    for (auto price : prices)
    {
        firstBuy = max(firstBuy, money - price);         // price at ith day
        firstSell = max(firstSell, firstBuy + price);    // max Profit using 1 transaction
        secondBuy = max(secondBuy, firstSell - price);   // price at ith day
        secondSell = max(secondSell, secondBuy + price); // money left after buying second stock
    }
    return secondSell;
}
int dp[50111][2];
int recur(vector<int> &prices, int i, int hold, int fee)
{
    if (i == prices.size())
        return 0;
    if (dp[i][hold])
        return dp[i][hold];
    if (hold)
    {
        int op1 = prices[i] + recur(prices, i + 1, 0, fee); // sell it
        int op2 = recur(prices, i + 1, 1, fee);             // don't sell it
        return dp[i][hold] = max(op1, op2);
    }
    else
    {

        int op1 = -prices[i] - fee + recur(prices, i + 1, 1, fee); // buy stock
        int op2 = recur(prices, i + 1, 0, fee);                    // don't buy
        return dp[i][hold] = max(op1, op2);
    }
}
int maxProfitIV(vector<int> &prices, int fee) // transaction
{
    memset(dp, 0, sizeof(dp));
    // return recur(prices, 0, 0, fee);
    int buy = INT_MIN, sell = 0;
    int lastBuy = INT_MIN, lastSell = 0;
    int money = 0;
    for (auto price : prices)
    {
        lastBuy = buy;
        lastSell = sell;
        buy = max(buy, lastSell - price - fee); // price at ith day
        sell = max(sell, lastBuy + price);      //
    }
    return sell;
}
int memo[10111][2][2];
int recur(vector<int> &prices, int i, int hold, int cooldown)
{
    if (i == prices.size())
        return 0;
    if (memo[i][hold][cooldown])
        return memo[i][hold][cooldown];
    if (hold)
    {
        int op1 = prices[i] + recur(prices, i + 1, 0, 1); // sell it
        int op2 = recur(prices, i + 1, 1, 0);             // don't sell it
        return memo[i][hold][cooldown] = max(op1, op2);
    }
    else
    {
        if (!cooldown)
        {
            int op1 = -prices[i] + recur(prices, i + 1, 1, cooldown); // buy stock
            int op2 = recur(prices, i + 1, 0, cooldown);              // don't buy
            return memo[i][hold][cooldown] = max(op1, op2);
        }
        else
        {
            return memo[i][hold][cooldown] = recur(prices, i + 1, 0, 0); // can't buy
        }
    }
}

int maxProfitV(vector<int> &prices)
{
    memset(dp, 0, sizeof(dp));
    return recur(prices, 0, 0, 0);
}
int BU(vector<int> &prices, int k)
{
    if (prices.size() < 2)
        return 0;
    if (k > prices.size() / 2)
        return maxProfitII(prices);
    for (int i = 1; i <= k; i++)
    {
        int res = INT_MIN;
        for (int j = 1; j <= prices.size(); j++)
        {
            res = max(res, dp[i - 1][j] - prices[j - 1]);
            dp[i][j] = max(dp[i][j - 1], res + prices[j - 1]);
        }
    }

    return dp[k][prices.size()];

    return dp[k][prices.size()];
}
int maxProfitVI(int k, vector<int> &prices)
{
    memset(dp, 0, sizeof(dp));
    int n = prices.size();
    return BU(prices, k);
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
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}