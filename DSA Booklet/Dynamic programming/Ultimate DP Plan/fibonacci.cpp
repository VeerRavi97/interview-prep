#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Leetcode Solution

class Solution
{
public:
  int fibII(int n)
  {
    if (n == 0)
      return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
  }

  int fib(int n)
  {
    if (n == 0)
      return 0;

    int a = 0;
    int b = 1;
    int c = a + b;
    for (int i = 2; i <= n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    return c;
  }
};

int main()
{
  // Driver
}