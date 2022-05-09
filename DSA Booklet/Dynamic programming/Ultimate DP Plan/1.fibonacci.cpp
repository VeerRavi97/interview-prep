#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution
{
public:
  int fibII(int n)
  {
    if (n <= 1)
      return n;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }

  int fib(int n)
  {
    if (n <= 1)
      return n;
    int secondPrev = 0;
    int prev = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++)
    {
      curr = prev + secondPrev;
      secondPrev = prev;
      prev = curr;
    }
    return prev;
  }

  int fibRecur(int n, vector<int> &dp)
  {
    if (n <= 1)
      return n;
    if (dp[n] != -1)
      return dp[n];
    return dp[n] = fib(n - 1) + fib(n - 2);
  }
  int fibR(int n)
  {
    vector<int> dp(n + 1, -1);
    return fibRecur(n, dp);
  }
};

void file_io()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  auto ip = freopen("input.txt", "r", stdin);
  auto op = freopen("output.txt", "w", stdout);
#endif
}

int main()
{
  clock_t start = clock();
  file_io();
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    Solution solution;
    auto ans = solution.fib(n);
    cout << ans << endl;
  }
  clock_t end = clock();
#ifndef ONLINE_JUDGE
  double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
  cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}