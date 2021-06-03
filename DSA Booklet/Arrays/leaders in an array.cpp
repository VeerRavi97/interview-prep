#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define all(c) (c).begin(), (c).end()
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);

const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll MAX_N = 1e5 + 5;

void solve(vi &v)
{
    if (v.size() == 1)
    {
        v[0] = -1;
        return;
    };
    int maxm = v[v.size() - 1];
    for (int i = v.size() - 2; i >= 0; i--)
    {
        if (v[i] >= maxm)
        {
            maxm = v[i];
        }
        else
        {
            v[i] = -1;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != -1)
        {
            cout << v[i] << " ";
        }
    }
    cout << "\n";
}

int main()
{
    fast;
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vi v;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        solve(v);
    }

    return 0;
}