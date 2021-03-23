#include <bits/stdc++.h>
using namespace std;
vector<string> mapped = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
string ans = "";
void solve(string input, int i)
{

  if (i == input.length())
  { // base case
    cout << ans << "\n";
    return;
  }
  int digit = input[i] - '0';
  for (int j = 0; j < mapped[digit].length(); j++)
  {
    char ch = mapped[digit][j];
    ans += ch;
    solve(input, i + 1);
    ans.pop_back(); // Backtrack
  }
}

int main()
{
  string input;
  while (cin >> input, input != "")
  {
    solve(input, 0);
  }

  return 0;
}