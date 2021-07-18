#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

void permuteHelper(set<vi> &res, vi &nums, int idx = 0)
{
    if (idx == nums.size())
    {
        res.insert(nums);
        return;
    }
    for (int j = idx; j < nums.size(); j++)
    {
        swap(nums[idx], nums[j]);
        permuteHelper(res, nums, idx + 1);
        swap(nums[j], nums[idx]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vvi res;
    set<vi> s;
    permuteHelper(s, nums);
    for (auto &v : s)
    {
        res.push_back(v);
    }
    return res;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = permute(v);
        for (auto &v : ans)
        {
            for (auto x : v)
                cout << x << " ";
            cout << endl;
        }
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}