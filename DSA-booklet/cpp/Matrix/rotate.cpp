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

void reverse(vvi &matrix, int n)
{
    for (int col = 0; col < n; col++)
    {
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            swap(matrix[start][col], matrix[end][col]);
            start++;
            end--;
        }
    }
}
void transpose(vvi &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    reverse(matrix, n);
    transpose(matrix, n);
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
        vvi matrix(n, vi(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        rotate(matrix);
        for (int i = 0; i < n; i++)
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