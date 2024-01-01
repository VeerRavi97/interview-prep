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
class Solution
{
public:
  double solve(vi &x, vi &y)
  {
    if (x.size() > y.size())
      return solve(y, x);
    double med = 0.0;
    int n = x.size();
    int m = y.size();
    int start = 0, end = n;
    while (start <= end)
    {
      int midX = (start + end) >> 1;
      int midY = ((n + m + 1) >> 1) - midX;
      int maxLeftX = (midX == 0) ? INT_MIN : x[midX - 1];
      int minRightX = (midX == n) ? INT_MAX : x[midX];
      int maxLeftY = (midY == 0) ? INT_MIN : y[midY - 1];
      int minRightY = (midY == m) ? INT_MAX : y[midY];
      if (maxLeftX <= minRightY && maxLeftY <= minRightX)
      {
        if ((n + m) & 1)
          return (double)max(maxLeftX, maxLeftY);
        else
        {
          return (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
        }
      }
      else if (maxLeftX > minRightY)
        end = midX - 1;
      else
        start = midX + 1;
    }

    return -1.0;
  }
};

int main()
{
  file_io();
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