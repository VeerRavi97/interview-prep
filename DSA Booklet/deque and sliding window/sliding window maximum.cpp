#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_CHAR 26

bool comp(int A[], int B[])
{
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

vector<int> solve(vector<int> &nums, int k)
{
    vector<int> res;
    deque<int> dq;
    int l = 0, r = 0;
    for (r = 0; r < k; r++) // applying the window
    {
        while (!dq.empty() && nums[r] >= nums[dq.back()])
            dq.pop_back();

        dq.push_back(r);
    }
    for (; r < nums.size(); r++) // expansion
    {
        res.push_back(nums[dq.front()]);
        int l = r - k + 1;
        while (!dq.empty() && dq.front() < l) // out of window
            dq.pop_front();

        while (!dq.empty() && nums[r] >= nums[dq.back()])
            dq.pop_back();
        dq.push_back(r);
    }
    res.push_back(nums[dq.front()]);
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
        int n, k;
        cin >> n >> k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        auto ans = solve(nums, k);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}