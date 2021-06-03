#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<char> vi;
typedef vector<vi> vvi;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int maxarea = INT_MIN;
    int curr_area = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && heights[s.top()] > heights[i])
        {
            int topped = s.top();
            s.pop();
            curr_area = (s.empty() ? heights[topped] * (i) : heights[topped] * (i - s.top() - 1));
            maxarea = max(maxarea, curr_area);
        }
        s.push(i);
    }
    while (!s.empty())
    {
        int topped = s.top();
        s.pop();
        curr_area = (s.empty() ? heights[topped] * (n) : heights[topped] * (n - s.top() - 1));
        maxarea = max(maxarea, curr_area);
    }
    return maxarea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    if (m < 1)
        return 0;
    int n = matrix[0].size();
    vector<int> temp(n, 0);
    int max_so_far = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] - '0')
                temp[j] += matrix[i][j] - '0';
            else
                temp[j] = 0;
        }
        int curr_area = largestRectangleArea(temp);
        max_so_far = max(max_so_far, curr_area);
    }
    return max_so_far;
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
        int m, n;
        cin >> m >> n;
        vvi v(m, vi(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        auto ans = maximalRectangle(v);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}