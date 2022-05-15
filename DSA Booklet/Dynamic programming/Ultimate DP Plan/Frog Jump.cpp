#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution
{
public:
    vector<int> stones;
    vvi dp;
    int n;
    bool recur(int idx, int pre)
    {
        if (idx == n - 1)
            return true;
        int &cached = dp[idx][pre];
        if (cached != -1)
            return cached;
        int lastJump = stones[idx] - stones[pre]; // k
        for (int i = idx + 1; i < n; i++)
        {
            int nextJump = stones[i] - stones[idx];
            if (nextJump >= lastJump - 1 && nextJump <= lastJump + 1)
            {
                bool ret = recur(i, idx);
                if (ret)
                    return cached = true;
            }
        }
        return cached = false;
    }
    bool canCrossTD(vector<int> &stones)
    {
        this->stones = stones;
        n = stones.size();
        // vvi temp(n + 1, vi(n + 1, -1));
        //  dp = temp;

        dp.resize(n + 1, vi(n + 1, -1));
        return recur(0, 0);
    }

    bool canCrossII(vector<int> &stones)
    {
        this->stones = stones;
        n = stones.size();
        vvi dp(n + 1, vi(n + 1, 0));
        for (int j = 0; j < n; j++)
            dp[n - 1][j] = 1;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int pre = n - 1; pre >= 0; pre--)
            {
                int lastJump = stones[idx] - stones[pre];
                int &cached = dp[idx][pre];
                for (int i = idx + 1; i < n; i++)
                {
                    int nextJump = stones[i] - stones[idx];
                    if (nextJump >= lastJump - 1 && nextJump <= lastJump + 1)
                    {
                        bool ret = dp[i][idx];
                        if (ret)
                        {
                            cached = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0];
    }

    bool canCross(vector<int> &stones)
    {

        unordered_map<int, set<int>> mp;
        int sz = stones.size();

        mp[0].insert(0);
        for (int i = 0; i < sz; i++)
        {
            for (int k : mp[stones[i]])
            {
                for (int step = k - 1; step <= k + 1; step++)
                {
                    if (step > 0)
                    {
                        mp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        return mp[stones[sz - 1]].size() > 0;
    }
};

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
        Solution solution;
        auto ans = solution.canCross(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}