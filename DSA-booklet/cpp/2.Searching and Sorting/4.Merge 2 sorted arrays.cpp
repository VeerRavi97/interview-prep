// https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

#include <bits/stdc++.h>
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
void merge(vector<int> &v1, vector<int> &v2, int n, int m)
{
    int len = n + m;
    int gap = (len / 2) + (len % 2 != 0);
    bool done = false;
    while (gap >= 1)
    {
        int i = 0;
        int j = gap;
        while (j < len)
        {
            if (i < n && j < n)
            {
                if (v1[i] > v1[j])
                    swap(v1[i], v1[j]);
            }
            else if (i >= n && j >= n)
            {
                if (v2[i - n] > v2[j - n])
                    swap(v2[i - n], v2[j - n]);
            }
            else if (i < n && j >= n)
            {
                if (v1[i] > v2[j - n])
                    swap(v1[i], v2[j - n]);
            }

            i++;
            j++;
        }

        gap = gap / 2 + (gap % 2 != 0);
        if (gap == 1 && done)
            break;
        if (gap == 1)
            done = true;
    }
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v1(n, 0);
        vector<int> v2(m, 0);
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v1[i] = in;
        }
        for (int i = 0; i < m; i++)
        {
            int in;
            cin >> in;
            v2[i] = in;
        }
        merge(v1, v2, n, m);
        for (auto x : v1)
        {
            cout << x << " ";
        }
        cout << endl;
        for (auto x : v2)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}