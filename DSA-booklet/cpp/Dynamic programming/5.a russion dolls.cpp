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
bool operator>(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first && a.second > b.second)
        return true;
    return false;
}
class Solution
{
public:
    int LISIII(vector<pair<int, int>> &v)
    {
        int dp_lis[10111];
        int lis = 1;
        for (int i = 0; i < v.size(); i++)
        {
            dp_lis[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (v[i] > v[j])
                {
                    dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
                    lis = max(lis, dp_lis[i]);
                }
            }
        }

        return lis;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        vector<pair<int, int>> v;
        for (auto x : envelopes)
        {
            v.push_back({x[0], x[1]});
        }
        sort(v.begin(), v.end());
        return LISIII(v);
    }
};

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    if (a.first == b.first && a.second > b.second)
        return true;
    return false;
}

class SolutionB
{
public:
    int lower_boundCCC(int start, int end, int key, int arr[], vector<pair<int, int>> &v)
    {
        int ans = end;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (v[arr[mid]].second == key)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (v[arr[mid]].second > key)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
    int LISIII(vector<pair<int, int>> &v)
    {
        if (v.size() == 0)
            return 0;
        int dp[10111];
        int parent[10111];
        int lis = 1;
        dp[0] = 0; // dp[0] = v[0]
        parent[0] = -1;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i].second > v[dp[lis - 1]].second)
            {
                dp[lis] = i;
                parent[i] = dp[lis - 1];
                lis++;
            }
            else
            {
                int idx = lower_boundCCC(0, lis, v[i].second, dp, v);
                dp[idx] = i;
                parent[i] = (idx > 0) ? dp[idx - 1] : -1;
            }
        }

        return lis;
    }
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        vector<pair<int, int>> v;
        for (auto x : envelopes)
        {
            v.push_back({x[0], x[1]});
        }
        sort(v.begin(), v.end(), comp);
        return LISIII(v);
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
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}