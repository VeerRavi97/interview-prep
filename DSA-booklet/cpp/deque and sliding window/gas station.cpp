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
int canCompleteCircuitII(vector<int> &gas, vector<int> &cost)
{
    deque<int> dq;
    int n = gas.size();
    int start = -1;
    int surplus = 0;
    // int deficit = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        surplus += gas[i % n] - cost[i % n];
        if (surplus < 0)
        {
            while (!dq.empty())
                dq.pop_back();
            start - 1;
            surplus = 0;
            continue;
        }
        if (start == i % n)
            break;
        if (dq.size() == 0)
            start = i;
        dq.push_back(gas[i % n]);
    }
    return ((dq.size() == n) ? start : -1);
}
int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int start = -1;
    int surplus = 0;
    int deficit = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        surplus += gas[i % n] - cost[i % n];
        if (surplus < 0)
        {
            deficit = surplus;
            surplus = 0;
            continue;
        }
        if (start == i % n)
            break;
        start = i;
    }
    return ((surplus - deficit >= 0) ? start : -1);
}
int canCompleteCircuitOptimal(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    int start = 0;
    int surplus = 0;
    int deficit = 0;
    bool isSelected = false;
    for (int i = 0; i < n; i++)
    {
        surplus += gas[i] - cost[i];
        if (surplus < 0)
        {
            start = i + 1;
            deficit -= surplus;
            surplus = 0;
        }
    }
    return ((surplus - deficit >= 0) ? start : -1);
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
        vi gas(n, 0);
        vi cost(n, 0);
        for (int i = 0; i < n; i++)
            cin >> gas[i];
        for (int i = 0; i < n; i++)
            cin >> cost[i];
        auto ans = canCompleteCircuit(gas, cost);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}