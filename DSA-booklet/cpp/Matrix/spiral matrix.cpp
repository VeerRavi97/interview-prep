#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int m = matrix.size();
    if (m == 0)
        return res;
    int n = matrix[0].size();
    int sr = 0, er = m - 1, sc = 0, ec = n - 1;
    while (sr <= er && sc <= ec)
    {
        for (int j = sc; j <= ec; j++)
            res.push_back(matrix[sr][j]);
        sr++;
        for (int i = sr; i <= er; i++)
            res.push_back(matrix[i][ec]);
        ec--;
        if (sr <= er)
        {
            for (int j = ec; j >= sc; j--)
                res.push_back(matrix[er][j]);
            er--;
        }
        if (sc <= ec)
        {
            for (int i = er; i >= sr; i--)
                res.push_back(matrix[i][sc]);
            sc++;
        }
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
        int m, n;
        cin >> m >> n;
        vvi matrix(m, vi(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        auto res = spiralOrder(matrix);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}