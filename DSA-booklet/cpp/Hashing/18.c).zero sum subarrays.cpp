#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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

int solve(vi &v)
{
  vii ans;
  unordered_map<ll, vi> mp;
  ll sum = 0;
  for (int i = 0; i < v.size(); i++)
  {
    sum += v[i];
    if (sum == 0)
      ans.push_back({0, i});
    if (mp.find(sum) != mp.end())
    {

      for (auto x : mp[sum])
      {
        ans.push_back({x + 1, i});
      }
    }
    mp[sum].push_back(i);
  }
  // for(auto x:ans){
  // cout << x.first << " " << x.second << "\n";

  // }

  return ans.size();
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