#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

void generateSmaller(vector<int> &v, vector<int> &psv, vector<int> &nsv)
{
    int n = v.size();
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[s.top()] > v[i])
        {
            int topped = s.top();
            s.pop();
            nsv[topped] = i;
        }
        psv[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
}

int largestRectangleAreaII(vector<int> &heights)
{
    int n = heights.size();
    vector<int> psv(n, -1);
    vector<int> nsv(n, n);
    generateSmaller(heights, psv, nsv);
    int maxarea = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int curr_area = 0;
        int leftArea = (psv[i] == -1 ? heights[i] * (i + 1) : heights[i] * (i - psv[i]));
        int rightArea = (nsv[i] == n ? heights[i] * (n - i - 1) : heights[i] * (nsv[i] - i - 1));
        curr_area = leftArea + rightArea;
        maxarea = max(maxarea, curr_area);
    }

    return maxarea;
}

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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = largestRectangleArea(v);
        cout << ans << endl;
        // for (auto x : v)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}