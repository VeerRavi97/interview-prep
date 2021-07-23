#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<string, int> psi;
typedef pair<int, int> pii;
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
class comp
{
public:
    bool operator()(state parent, state curr)
    {
        if (curr.freq < parent.freq)
            return true;
        if (parent.freq == curr.freq && curr.word > parent.word)
            return true;
        return false;
    }
    bool operator()(pii parent, pii curr)
    {
        return curr.first < parent.first;
    }
};
vector<int> solve(vector<int> &v, int k)
{
    vector<int> res;
    map<int, int> mp;
    for (auto x : v)
        mp[x]++;
    priority_queue<pair<int, int>> pq;
    for (auto x : mp)
    {
        pq.push({x.second, x.first});
    }
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}
vector<int> solveII(vector<int> &v, int k)
{
    vector<int> res;
    unordered_map<int, int> mp;
    for (auto x : v)
        mp[x]++;
    priority_queue<pii, vector<pii>, comp> pq; // max heap
    for (auto x : mp)
    {
        pq.push({x.second, x.first});
        if (pq.size() > k)
            pq.pop();
    }
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

struct state
{
    string word;
    int freq;
};

vector<string> solveIII(vector<string> &words, int k)
{
    vector<string> res;
    map<string, int> mp;
    for (auto x : words)
        mp[x]++;
    priority_queue<state, vector<state>, comp> pq;
    int cnt = 1;
    for (auto x : mp)
    {
        state curr;
        curr.freq = x.second;
        curr.word = x.first;
        pq.push(curr);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().word);
        pq.pop();
    }
    reverse(all(res));
    return res;
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
        vs v(n, "");
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int k;
        cin >> k;
        auto ans = solveIII(v, k);
        //cout << ans << endl;
        for (auto x : ans)
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