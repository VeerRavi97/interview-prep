// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool visited[10111] = {0};
    bool recStack[10111] = {0};
    bool check(int src, vector<int> adj[])
    {
        visited[src] = 1;
        recStack[src] = 1;
        for (auto nbr : adj[src])
        {
            if (recStack[nbr])
                return true;
            if (!visited[nbr] && check(nbr, adj))
                return true;
        }
        recStack[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        for (int i = 0; i <= V; i++)
        {
            visited[i] = 0;
            recStack[i] = 0;
        }
        bool exists = 0;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                exists = check(i, adj);
            }
            if (exists)
                break;
        }
        return exists;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}