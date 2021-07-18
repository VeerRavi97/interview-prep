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

const ll MOD = 1e9 + 7;
const ll INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll MAX_N = 1e5 + 5;

class Solution
{
public:
  double solve(vi &a, vi &b)
  {
    if (b.size() < a.size())
      return solve(b, a);
    double med = 0.0;
    int m = a.size();
    int n = b.size();
    int len_leftpart = (m + n + 1) / 2;
    int start = 0; // a'minimum contribution to left part of median
    int end = m;   // a's maximum contribution to left part of median
    while (start <= end)
    {
      int mid = (start + end) / 2;
      int a_contribution = mid;
      int b_contribution = len_leftpart - a_contribution;
      cout << start << " " << end << " " << mid << " " << a_contribution << " " << b_contribution << "\n";
      int x, x1, y, y1;
      if (a_contribution == 0)
        x = INT32_MIN;
      else
        x = a[a_contribution - 1];
      if (a_contribution == m)
        x1 = INT32_MAX;
      else
        x1 = a[a_contribution];
      if (b_contribution == 0)
        y = INT32_MIN;
      else
        y = b[b_contribution - 1];
      if (b_contribution == n)
        y1 = INT32_MAX;
      else
        y1 = b[b_contribution];
      cout << x << " " << x1 << " " << y << " " << y1 << "\n";
      if (x <= y1 && y <= x1)
      {
        if ((m + n) & 1)
          return (double)max(x, y);
        else
        {
          return (double)(max(x, y) + min(x1, y1)) / 2;
        }
      }
      else if (y > x1)
        start = a_contribution + 1;
      else if (x > y1)
        end = a_contribution - 1;
    }

    return -1.0;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {

    int m, n;
    cin >> m >> n;
    vi a, b;
    for (int i = 0; i < m; i++)
    {
      int in;
      cin >> in;
      a.push_back(in);
    }
    for (int i = 0; i < n; i++)
    {
      int in;
      cin >> in;
      b.push_back(in);
    }

    Solution A;
    double ans = A.solve(a, b);

    cout << ans << "\n";
  }

  return 0;
}