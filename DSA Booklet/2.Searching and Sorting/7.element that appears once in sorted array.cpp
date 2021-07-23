#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define all(c) (c).begin(), (c).end()
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);
#define deb(x) cout << #x << " " << x << "\n";

const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll MAX_N = 1e5 + 5;

int solve(vi &v)
{
  int n = v.size();
  int start = 0;
  int end = n - 1;
  while (start <= end)
  {
    if (start == end)
      return v[start];
    int mid = (start + end) / 2;
    if (mid & 1)
    { // if occurence is at odd position
      if (v[mid] == v[mid - 1])
        start = mid + 1; // all elemnets on left are at thier positions
      else
      {
        end = mid - 1; // the required element is on left
      }
    }
    else
    {
      if (v[mid] == v[mid + 1])
        start = mid + 1;
      else
      {
        end = mid;
      }
    }
  }

  return -1;
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
    int ans = solve(v);
    cout << ans << "\n";
  }

  return 0;
}