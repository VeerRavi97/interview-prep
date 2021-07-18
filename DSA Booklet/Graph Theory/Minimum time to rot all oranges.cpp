#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

class Coordinate
{
public:
    int x;
    int y;
    Coordinate(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool isValid(vector<vector<int>> &grid, int i, int j)
{
    int m = grid.size();
    if (m == 0)
        return false;
    int n = grid[0].size();
    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
        return true;
    return false;
}

int orangesRotting(vector<vector<int>> &grid)
{
    int dx[4] = {-1, 0, +1, 0};
    int dy[4] = {0, +1, 0, -1};
    int m = grid.size();
    if (m == 0)
        return false;
    int n = grid[0].size();
    queue<Coordinate> q;
    int timeElapsed = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                Coordinate coordinate(i, j);
                q.push(coordinate);
            }
        }
    }
    while (!q.empty())
    {
        int count = q.size();
        bool isAnyFreshOrangeRotten = false;
        for (int i = 0; i < count; i++)
        {
            Coordinate curr = q.front();
            q.pop();
            for (int nth = 0; nth < 4; nth++)
            {
                int nbrX = curr.x + dx[nth];
                int nbrY = curr.y + dy[nth];
                if (isValid(grid, nbrX, nbrY))
                {
                    grid[nbrX][nbrY] = 2;
                    isAnyFreshOrangeRotten = true;
                    Coordinate coordinate(nbrX, nbrY);
                    q.push(coordinate);
                }
            }
        }
        if (isAnyFreshOrangeRotten)
            timeElapsed++;
        else
            break;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    return timeElapsed;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        int n, m;
        cin >> m >> n;
        vvi grid(m, vi(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        auto ans = orangesRotting(grid);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}