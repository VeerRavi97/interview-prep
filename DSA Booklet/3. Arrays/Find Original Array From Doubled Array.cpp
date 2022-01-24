#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vector<int> findOriginalArray(vector<int> &changed)
{
    int n = changed.size();
    vector<int> res;
    if (n & 1)
        return res;
    sort(all(changed));
    unordered_map<int, int> mp;
    for (int &x : changed)
        mp[x]++;

    for (int &ele : changed)
    {
        int doubled = 2 * ele;
        if (ele == 0 && mp[ele] >= 2)
        {
            mp[ele] -= 2;
            res.push_back(ele);
        }
        else if (ele != 0 && mp[ele] > 0 && mp[doubled] > 0)
        {
            mp[ele]--;
            mp[doubled]--;
            res.push_back(ele);
        }
    }
    if (res.size() == n / 2)
        return res;
    res.clear();
    return res;
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
        auto ans = findOriginalArray(v);
        for (auto &x : ans)
            cout << x << " ";
        cout << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}