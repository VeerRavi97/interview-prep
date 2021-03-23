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
vector<int> intersectionUnique(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> space;
    vector<int> v;
    for (auto x : nums1)
        space.insert(x);
    for (auto x : nums2)
    {
        if (space.count(x))
        {
            v.push_back(x);
            space.erase(x); // avoid Duplicates
        }
    }
    return v;
}

vector<int> intersectionAll(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> space;
    for (auto x : nums1)
        space[x]++;
    vector<int> v;
    for (auto x : nums2)
    {
        if (space.count(x) && space[x] > 0)
        {
            v.push_back(x);
            space[x]--;
        }
    }

    return v;
}
vector<int> unionUnique(vector<int> &a, vector<int> &b)
{
    unordered_set<int> s;
    for (auto x : a)
        s.insert(x);
    for (auto x : b)
        s.insert(x);
    vector<int> v;
    for (auto x : s)
        v.push_back(x);
    return v;
}
vector<int> unionAll(vector<int> &a, vector<int> &b)
{
    unordered_map<int, int> mp;
    for (auto x : a)
        mp[x]++;
    vector<int> v;
    for (auto x : b)
    {
        if (mp.count(x) && mp[x] > 0)
        {
            v.push_back(x);
            mp[x]--;
        }
        else
        {
            mp[x]++;
        }
    }
    for (auto x : mp)
    {
        for (int i = 0; i < x.second; i++)
            v.push_back(x.first);
    }
    return v;
}
int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vi v1(n, 0), v2(m, 0);
        for (int i = 0; i < n; i++)
            cin >> v1[i];
        for (int i = 0; i < m; i++)
            cin >> v2[i];
        vi res = intersectionUnique(v1, v2);
        cout << "intersection Unique : ";
        for (auto num : res)
            cout << num << " ";
        cout << endl;
        cout << "intersection All : ";
        res = intersectionAll(v1, v2);
        for (auto num : res)
            cout << num << " ";
        cout << endl;
        cout << "Union Unique : ";
        res = unionUnique(v1, v2);
        for (auto num : res)
            cout << num << " ";
        cout << endl;
        cout << "Union All : ";
        res = unionAll(v1, v2);
        for (auto num : res)
            cout << num << " ";
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}