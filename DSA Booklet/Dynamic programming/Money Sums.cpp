#include <iostream>
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

int subsetSums(vector<int> &v, int n, int range)
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

int main()
{
    // clock_t start = clock();
    file_io();
    int tc;
    tc = 1;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
            range += in;
        }
        subsetSums(v, n, range);
    }

    //     clock_t end = clock();
    // #ifndef ONLINE_JUDGE
    //     double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    //     cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
    // #endif
}