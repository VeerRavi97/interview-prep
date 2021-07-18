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

int solve(vi &v)
{
    int n = v.size();
    int m = v[0];
    int cnt = 1;
    // cout << cnt << " " << m<< "\n";
    for (int i = 1; i < n; i++)
    {
        if (m == v[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            m = v[i];
            cnt = 1;
        }
        // cout << cnt << " " << m << "\n";
    }

    if (cnt < 0)
        return -1;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == m)
            cnt++;
    }
    if (cnt > n / 2)
        return m;
    return -1;
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

        int ans = solve(v);
        cout << ans << "\n";
    }

    return 0;
}