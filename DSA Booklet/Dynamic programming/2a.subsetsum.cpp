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

int allSums(vector<int> &v, int n, int range)
{
    vector<int> possible(range + 1, 0);
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
    for (int i = 1; i <= range; i++)
    {
        if (possible[i])
            cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= range; i++)
    {
        if (possible[i])
            cout << i << " ";
    }
    cout << endl;

    return 1;
}
bool isValid(int r, int c)
{
    return (r >= 0 && c >= 0);
}
void dfs(vector<vector<int>> &dp, vector<int> &v, int r, int c, string path)
{
    if (r == 0 || c == 0)
    {
        cout << path << endl;
        return;
    }

    if (dp[r - 1][c] > 0)
    {
        int rnbr = r - 1;
        int cnbr = c;
        if (isValid(rnbr, cnbr))
            dfs(dp, v, rnbr, cnbr, path);
    }
    stringstream ss;
    ss << v[r - 1];
    string temp = "";
    ss >> temp;
    int rnbr = r - 1;
    int cnbr = c - v[r - 1];
    if (isValid(rnbr, cnbr) && dp[rnbr][cnbr] > 0)
        dfs(dp, v, rnbr, cnbr, path + temp);
}

int isSubsetRecurIII(vector<int> &v, vector<vector<int>> &dp, int n, int target, int csum = 0, int idx = 0)
{
    if (idx == n)
    {
        if (csum == target)
            return dp[idx][csum] = 1;
        return dp[idx][csum] = 0;
    }
    if (dp[idx][csum] != -1)
        return dp[idx][csum];
    int exclude = isSubsetRecurIII(v, dp, n, target, csum, idx + 1);
    int include = 0;
    if (csum + v[idx] <= target)
        include = isSubsetRecurIII(v, dp, n, target, csum + v[idx], idx + 1);
    return dp[idx][csum] = (include || exclude);
}

int isSubsetRecurII(vector<int> &v, vector<vector<int>> &dp, int n, int target, int idx = 0)
{
    if (target == 0)
        return 1;
    if (idx == n)
    {
        if (target == 0)
            return dp[idx][target] = 1;
        return dp[idx][target] = 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];
    int exclude = isSubsetRecurII(v, dp, n, target, idx + 1);
    int include = 0;
    if (v[idx] <= target)
        include = isSubsetRecurII(v, dp, n, target - v[idx], idx + 1);
    return dp[idx][target] = (include || exclude);
}

int isSubsetRecur(vector<int> &v, vector<vector<int>> &dp, int idx, int target)
{
    if (target == 0)
        return 1;
    if (idx == 0)
        return (v[idx] == target);

    if (dp[idx][target] != -1)
        return dp[idx][target];
    int exclude = isSubsetRecur(v, dp, idx - 1, target);
    int include = 0;
    if (v[idx] <= target)
        include = isSubsetRecur(v, dp, idx - 1, target - v[idx]);
    return dp[idx][target] = (include || exclude);
}

int isSubsetSumTD(vector<int> &v, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1));
    return isSubsetRecur(v, dp, n, target);
}

/**
 * URL: https://www.interviewbit.com/problems/subset-sum-problem/
 */
int isSubsetSum(vector<int> &v, int n, int target)
{
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (v[0] <= target)
        dp[0][v[0]] = 1;
    for (int idx = 1; idx < n; idx++)
    {
        int curr = v[idx];
        for (int wt = 1; wt <= target; wt++)
        {
            bool exclude = dp[idx - 1][wt];
            bool include = 0;
            if (curr <= wt)
                include = dp[idx - 1][wt - curr]; // + , count

            dp[idx][wt] = include || exclude;
        }
    }
    //  string path = " ";
    //  dfs(dp, v, n, target, path);
    return dp[n - 1][target];
}

/**
 * URL: https://www.interviewbit.com/problems/subset-sum-problem/
 */
int isSubsetSumSpaceOptimized(vector<int> &v, int n, int target)
{
    vector<int> curr(target + 1, 0), prev(target + 1, 0);
    curr[0] = 1, prev[0] = 1;
    if (v[0] <= target)
        prev[v[0]] = 1;
    for (int idx = 1; idx < n; idx++)
    {
        int curr_w = v[idx];
        for (int wt = 1; wt <= target; wt++)
        {
            bool exclude = prev[wt];
            bool include = 0;
            if (curr_w <= wt)
                include = prev[wt - curr_w]; // + , count

            curr[wt] = include || exclude;
        }
        prev = curr;
    }
    //  string path = " ";
    //  dfs(dp, v, n, target, path);
    return prev[target];
}

int isSubsetSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    // dp[nums[0]]=1;
    for (int idx = 0; idx < n; idx++)
    {
        int curr_w = nums[idx];
        for (int wt = target; wt >= curr_w; wt--)
        {
            dp[wt] |= dp[wt - curr_w];
        }
    }
    return dp[target];
}

/**
 * @brief
 * URL: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633
 */

int countSubsets(vector<int> &nums, int target)
{
    vector<int> possible(target + 1, 0);
    possible[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        int curr = nums[i];
        for (int j = target; j >= curr; j--)
        {
            possible[j] = (possible[j] + possible[j - curr]) % MOD;
        }
        return possible[target] % MOD;
    }
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (int num : nums)
        sum += num;
    return isSubsetSum(nums, nums.size(), (target + sum) >> 1);
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
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
        int cnt = findTargetSumWays(v, target);
        cout << cnt << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}