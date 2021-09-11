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

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    if (m == 0)
        return;
    int n = matrix[0].size();
    int colOne = 1;
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
            colOne = 0;
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
                matrix[0][j] = matrix[i][0] = 0;
        }
    }
    //  for(int i=0;i<m;i++) {
    //      cout << matrix[i][0] <<  " ";
    //  }
    // cout << endl;
    // cout << colOne << " ";         s
    //  for(int j=1;j<n;j++) {
    //      cout << matrix[0][j] <<  " ";
    //  }
    //  cout << endl;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            cout << "(" << matrix[i][0] << "," << matrix[0][j] << ")"
                 << " ";
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        if (colOne == 0)
            matrix[i][0] = 0;
    }
    for (int j = 1; j < n; j++)
    {
        if (matrix[0][0] == 0)
            matrix[0][j] = 0;
    }
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
        setZeroes(matrix);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}