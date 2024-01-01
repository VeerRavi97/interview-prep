#include <iostream>
#include <vector>
using namespace std;
const int N = 15;
#define all(c) (c).begin(), (c).end()
vector<int> mat[N];
vector<int> sol[N];
int n = 0;
bool issafe(int i, int j)
{

  if (i >= 0 && j >= 0 && i < n && j < mat[i].size() && mat[i][j])
  {
    return true;
  }

  return false;
}

bool solve(int i, int j, vector<string> &v)
{

  // Base Case
  if (i == n - 1 && j == mat[i].size() - 1)
  {
    string ans = "";
    sol[i][j] = 1;
    for (int k = 0; k < n; k++)
    {
      for (int l = 0; l < n; l++)
      {
        // cout << sol[k][l] << " ";
        if (k - 1 >= 0 && sol[k - 1][l] && sol[k][l])
          ans += "D";
        if (l - 1 >= 0 && sol[k][l - 1] && sol[k][l])
          ans += "R";
      }
      //    cout << "\n";
    }

    v.push_back(ans);
    //  cout <<  ans << "\n";
    return true;
  }

  // Recursive Case
  // cout << i << " " << j << " ";
  if (issafe(i, j))
  {
    //    cout << "safe" << "\n";

    sol[i][j] = 1; // visited
    bool right = solve(i, j + 1, v);
    bool down = solve(i + 1, j, v);
    sol[i][j] = 0;
    if (right || down)
      return true;

    return true;
  }
  //   cout << "not safe\n";
  return false;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--)
  {
    memset(mat, 0, sizeof(mat));
    memset(sol, 0, sizeof(sol));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int in;
        cin >> in;
        mat[i].push_back(in);
        sol[i].push_back(0);
      }
    }
    //  for(int i=0;i<n;i++){
    //    for(int j=0;j<n;j++){
    //       cout << mat[i][j] << " ";
    //    }
    //    cout << "\n";
    //  }
    //  cout << "\n";
    vector<string> v;
    solve(0, 0, v);
    sort(all(v));
    for (auto x : v)
    {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}