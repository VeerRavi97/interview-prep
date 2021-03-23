#include <bits/stdc++.h>
using namespace std;
string ans = "";
void recurse(string in, int k)
{
  // Base case
  if (k == in.length())
  {
    cout << ans << "\n";
    return;
  }

  // Recursive case

  ans.push_back(in[k]);

  recurse(in, k + 1);
  ans.pop_back();
  //    cout << ans << "\n";
  recurse(in, k + 1);
}

int main()
{

  string in;
  while (cin >> in)
  {
    recurse(in, 0);
  }
}