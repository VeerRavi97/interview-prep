#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && temperatures[s.top()] < temperatures[i])
        {
            int tp = s.top();
            s.pop();
            res[tp] = i - tp;
        }

        s.push(i);
    }

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
        auto ans = dailyTemperatures(v);
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}