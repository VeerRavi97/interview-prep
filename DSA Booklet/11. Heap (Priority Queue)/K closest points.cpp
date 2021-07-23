#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef pair<int, int> pii;
struct state
{
    int distance;
    int x;
    int y;
};
int distance(int a, int b)
{
    double temp = a * a + b * b;
    return temp; // sqrt(temp)
}

class comp
{
public:
    bool operator()(state a, state b)
    {
        return b.distance > a.distance;
    }
};

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{

    vector<vi> res(k);
    priority_queue<state, vector<state>, comp> pq; // max heap
    for (auto x : points)
    {
        state curr;
        curr.x = x[0];
        curr.y = x[1];
        curr.distance = distance(curr.x, curr.y);
        pq.push(curr);
        if (pq.size() > k)
            pq.pop();
    }
    for (int i = 0; i < k; i++)
    {
        res[i].push_back(pq.top().x);
        res[i].push_back(pq.top().y);
        pq.pop();
    }
    return res;
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
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            v[i].push_back(x);
            v[i].push_back(y);
        }
        int k;
        cin >> k;
        auto ans = kClosest(v, k);
        // cout << ans << endl;
        for (auto x : ans)
        {
            for (auto ele : x)
                cout << ele << " ";
            cout << endl;
        }
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}