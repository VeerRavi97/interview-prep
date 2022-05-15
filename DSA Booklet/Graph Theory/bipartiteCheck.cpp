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
#define MAX_N 10111
class Graph
{
    int v, e;
    vvi adj;
    vi visited;

public:
    Graph(int v = 0, int e = 0)
    {
        this->v = v;
        this->e = e;
        adj.resize(v + 1, vi(v + 1, 0));
    }
    void addEdge(int src, int dest, int UNDIR = true)
    {
        adj[src].push_back(dest);
        if (UNDIR)
            adj[dest].push_back(src);
    }
    bool DFS_Helper(int src, int color)
    {
        visited[src] = color;
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool isBipartite = DFS_Helper(nbr, 3 - color);
                if (!isBipartite)
                    return false;
            }
            else if (visited[nbr] && color == visited[nbr])
                return false;
        }
        return true;
    }
    bool isBipartite()
    {
        visited.resize(v + 1, 0);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool ret = DFS_Helper(i, 1);
                if (!ret)
                    return false;
            }
        }
        return true;
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
        int n, m;
        int src, dest;
        cin >> n >> m;
        Graph graph(n, m);
        for (int i = 0; i < m; i++)
        {
            cin >> src >> dest;
            graph.addEdge(src, dest);
        }
        auto ans = graph.isBipartite();
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}