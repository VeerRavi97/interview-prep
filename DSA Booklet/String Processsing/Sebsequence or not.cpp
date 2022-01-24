#include <iostream>
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

string solve(string full, string abb)
{
    int m = full.length();
    int n = abb.length();
    string ans = "";
    int j = 0;
    for (int i = 0; i < m; i++)
        if (full[i] != abb[j])
            ans += full[i];
        else
            j++;
    return ans;
}

int main()
{
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--)
    {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        string ans = solve(s1, s2);
        cout << ans << "\n";
    }

    return 0;
}