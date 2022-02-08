#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> ii;
#define MAXN 101111
int lower_boundCC(int start, int end, int key, int arr[], vector<int> &v)
{
    int ans = end;
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (v[arr[mid]] == key)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (v[arr[mid]] > key)
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
int LISII(vector<int> &v)
{
    if (v.size() == 0)
        return 0;
    int dp[MAXN];
    int parent[MAXN];
    int lis = 1;
    dp[0] = 0; // dp[0] = v[0]
    parent[0] = -1;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > v[dp[lis - 1]])
        {
            dp[lis] = i;
            parent[i] = dp[lis - 1];
            lis++;
        }
        else
        {
            int idx = lower_boundCC(0, lis, v[i], dp, v);
            dp[idx] = i;
            parent[i] = (idx > 0) ? dp[idx - 1] : -1;
        }
    }

    return lis;
}

int findNumberOfLIS(vector<int> &v)
{
    int dp[v.size() + 1];
    int cnt[v.size() + 1];
    int lis = 1;
    int count = 0;
    for (int i = 0; i < v.size(); i++)
    {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (dp[j] + 1 == dp[i])
                {
                    cnt[i] += cnt[j];
                }

                lis = max(lis, dp[i]);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (lis == dp[i])
            count += cnt[i];
    }

    return count;
}

int LIS(vector<int> &v)
{
    int dp_lis[MAXN];
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

int minimumMountainRemovals(vector<int> &v)
{
    int dp_lis[MAXN];
    int dp_lds[MAXN];
    int lis = 1;
    for (int i = 0; i < v.size(); i++)
    {
        dp_lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
            {
                dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
            }
        }
    }
    dp_lds[v.size() - 1] = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--)
    {
        dp_lis[i] = 1;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] > v[j])
            {
                dp_lds[i] = max(dp_lds[i], dp_lds[j] + 1);
            }
        }
    }
    int global = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        int local = dp_lis[i] + dp_lds[i] - 1;
        int global = max(global, local);
    }

    return global;
}
bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    if (a.first == b.first && a.second > b.second)
        return true;
    return false;
}
inline bool operator>(ii a, ii b) // for Envelopes
{
    if (a.first > b.first && a.second > b.second)
        return true;
    return false;
}

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
        if (v[i] > v[dp[lis - 1]])
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = minimumMountainRemovals(v);
        cout << ans << endl;
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}