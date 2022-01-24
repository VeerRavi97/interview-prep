#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_N 10111

void sanitize(vector<string> &words, vector<int> &freq)
{
    for (string &str : words)
    {
        for (char ch : str)
            freq[ch - 'a']++;
    }
}

class Graph
{
    int V, E;
    set<int> adj[26];

public:
    Graph(int V, int E = 0)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int src, int dest, int DIR = false)
    {
        adj[src].insert(dest);
        if (!DIR)
            adj[dest].insert(src);
    }
    bool dfs(int src, vector<int> &visited, vector<int> &recStack, string &res)
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
        res += (src + 'a');
        return false;
    }
    void dfsWrapper(string &res, vector<int> &freq)
    {
        vector<int> visited(V, 0);
        vector<int> recStack(V, 0);
        bool isCyclic = false;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && freq[i] > 0)
            {
                isCyclic = dfs(i, visited, recStack, res);
                if (isCyclic)
                    break;
            }
        }
        if (isCyclic)
            res = "";
        else
            reverse(res.begin(), res.end());
        return;
    }

    void bfs(vector<int> &inDegree, vector<int> &freq, string &res)
    {
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0 && freq[i] > 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res += (u + 'a');
            for (int nbr : adj[u])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }

    void bfsWrapper(string &res, vector<int> &freq)
    {
        vector<int> inDegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int x : adj[i])
                inDegree[x]++;
        }
        bfs(inDegree, freq, res);
        return;
    }
};

string alienOrder(vector<string> &words)
{
    Graph graph(26);
    vector<int> freq(26);
    sanitize(words, freq);
    string res;
    int sz = words.size();
    for (int i = 1; i < sz; i++)
    {
        string srcWord = words[i - 1];
        string destWord = words[i];
        int lenA = srcWord.length();
        int lenB = destWord.length();
        int minLen = min(lenA, lenB);
        if (lenA > lenB && srcWord.substr(0, minLen) == destWord.substr(0, minLen))
            return "";

        for (int j = 0; j < minLen; j++)
        {
            int dest = destWord[j] - 'a';
            int src = srcWord[j] - 'a';
            if (src != dest)
            {
                graph.addEdge(src, dest, 1);
                break;
            }
        }
    }
    graph.dfsWrapper(res, freq);
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
        int n;
        cin >> n;
        vector<string> words(n);
        for (int i = 0; i < n; i++)
        {
            cin >> words[i];
        }
        auto ans = alienOrder(words);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}