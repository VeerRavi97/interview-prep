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

void printDuplicates(vi &v)
{

    bool flag = false;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int index = v[i] % n;
        v[index] += n;
        if (v[index] / n == 2)
        {
            cout << index << " ";
            flag = true;
        }
    }

    if (!flag)
    {
        cout << -1;
    }
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
        printDuplicates(v);
    }

    return 0;
}