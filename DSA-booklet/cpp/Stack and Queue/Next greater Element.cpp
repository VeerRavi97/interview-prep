#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> s;
    for (int i = 0; i < 2 * n; i++)
    {
        while (!s.empty() && nums[s.top()] < nums[i % n])
        {
            int topped = s.top();
            s.pop();
            res[topped] = nums[i % n];
        }
        if (i < n)
            s.push(i);
    }
    // while (s.size() > 2)
    // {
    //     int topped = s.top();
    //     s.pop();
    //     res[topped] = nums[s.top()];
    // }
    return res;
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
        auto ans = nextGreaterElements(v);
        // cout << ans << endl;
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}