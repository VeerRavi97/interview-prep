#include <iostream>
using namespace std;
int power(int x, int n)
{
  if (n == 0)
    return 1;
  int temp = power(x, n / 2);
  if (n & 1)
    return x * temp * temp;
  return temp * temp;
}
int main()
{
  int x, n;
  while (cin >> x >> n, n > 0)
  {
    cout << power(x, n) << "\n";
  }
}