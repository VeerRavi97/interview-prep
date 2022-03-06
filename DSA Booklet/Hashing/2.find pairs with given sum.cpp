#include <iostream>
#include <unordered_map>
#include <vector>
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
int findPairs(vector<int> &v, int n, int target)
{
    unordered_map<int, int> mp;
    long long count = 0;
    for (auto first : v)
    {
        int second = target - first;
        count += mp[second];
        mp[first]++;
    }

    return count;
}
int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        cout << findPairs(v, n, x) << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}

// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1