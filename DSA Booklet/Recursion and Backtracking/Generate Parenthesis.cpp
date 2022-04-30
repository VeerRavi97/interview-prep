#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
public:
    void recur(vector<string> &res, int n, int no = 0, int nc = 0, string curr = "", int idx = 0)
    {
        if (idx == 2 * n)
        {
            res.push_back(curr);
            return;
        }
        if (no < n)
        {
            recur(res, n, no + 1, nc, curr + '(', idx + 1);
        }
        if (nc < no)
        {
            recur(res, n, no, nc + 1, curr + ')', idx + 1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        recur(res, n);
        return res;
    }
};

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
        Solution solution;
        auto ans = solution.generateParenthesis(n);
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