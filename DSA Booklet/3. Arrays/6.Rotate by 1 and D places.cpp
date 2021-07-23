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

void anticlock_rotate(vi &v, int d)
{
    // right rotation
    int n = v.size();
    reverse(v.begin(), v.begin() + (n - d));
    reverse(v.begin() + (n - d), v.end());
    reverse(all(v));
}
void clock_rotate(vi &v, int d)
{
    int n = v.size();
    reverse(v.begin(), v.begin() + d);
    reverse(v.begin() + d, v.end());
    reverse(all(v));
}

int main()
{
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
        int d;
        cin >> d;
        vi v1(v);
        anticlock_rotate(v1, d);
        for (auto x : v1)
        {
            cout << x << " ";
        }
        cout << "\n";
        clock_rotate(v, d);
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}