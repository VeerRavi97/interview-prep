#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
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
    int V, E;
    list<int> *adj;

public:
    Graph(int V, int E = 0)
    {
        this->V = V;
        this->E = E;
        this->adj = new list<int>[V];
    }
    void addEdge(int src, int dest, int DIR = false)
    {
        adj[src].push_back(dest);
        if (!DIR)
            adj[dest].push_back(src);
    }
    bool dfs(int src, vector<int> &visited, vector<int> &recStack, vector<int> &res)
    {
        visited[src] = 1;
        recStack[src] = 1;
        for (int nbr : adj[src])
        {
            if (recStack[nbr])
                return true;
            else if (!visited[nbr])
            {
                bool isCyclic = dfs(nbr, visited, recStack, res);
                if (isCyclic)
                    return true;
            }
        }
        recStack[src] = 0;
        res.push_back(src);
        return false;
    }
    void dfsWrapper(vector<int> &res)
    {
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        bool isCyclic = false;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                isCyclic = dfs(i, visited, recStack, res);
                if (isCyclic)
                    break;
            }
        }
        if (isCyclic)
            res.clear();
        else
            reverse(res.begin(), res.end());
        return;
    }

    void bfs(vector<int> &res, vector<int> &inDegree)
    {
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int nbr : adj[u])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    void bfsWrapper(vector<int> &res)
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int x : adj[i])
                inDegree[x]++;
        }
        bfs(res, inDegree);
        if (res.size() != V)
            res.clear();
        return;
    }
};

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int sz = prerequisites.size();
    Graph graph(numCourses, sz);
    vector<int> res;
    for (int i = 0; i < sz; i++)
    {
        graph.addEdge(prerequisites[i][1], prerequisites[i][0], 1);
    }
    graph.bfsWrapper(res);
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
        int n, m;
        int src, dest;
        cin >> n >> m;
        vector<vector<int>> prerequisites(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            cin >> dest >> src;
            prerequisites[i][0] = dest;
            prerequisites[i][1] = src;
        }
        auto ans = findOrder(n, prerequisites);
        for (int x : ans)
            cout << x << " ";
        cout << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}