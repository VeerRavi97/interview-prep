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
  double solve(vi &a, vi &b, int start_a, int end_a, int start_b, int end_b)
  {

    double med = 0.0;
    if (end_a - start_a == 1 && end_b - start_b == 1)
    {
      //  cout << max(a[start_a],b[start_b]) << " " << min(a[end_a],b[end_b]) << "\n";
      med = (double)(max(a[start_a], b[start_b]) + min(a[end_a], b[end_b])) / 2;
      return med;
    }
    int m1_index = (start_a + end_a) / 2;
    int m2_index = (start_b + end_b) / 2;
    int m1 = a[m1_index];
    int m2 = b[m2_index];
    if (m1 == m2)
      return m1;
    else if (m1 < m2)
    {
      start_a = m1_index;
      end_b = m2_index;
      return solve(a, b, start_a, end_a, start_b, end_b);
    }
    else
    {
      start_b = m2_index;
      end_a = m1_index;
      return solve(a, b, start_a, end_a, start_b, end_b);
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

    int n;
    cin >> n;
    vi a, b;
    for (int i = 0; i < n; i++)
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
    double ans = A.solve(a, b, 0, n - 1, 0, n - 1);

    cout << ans << "\n";
  }

  return 0;
}