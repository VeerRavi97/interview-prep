#include <iostream>
#include <vector>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define fast               \
  ios::sync_with_stdio(0); \
  cin.tie(0);

void sortColors(vector<int> &nums)
{
  int n = nums.size();
  int low = 0, high = n - 1;
  int mid = 0;
  while (mid <= high)
  {
    if (nums[mid] == 0)
      swap(nums[low++], nums[mid++]);
    else if (nums[mid] == 2)
      swap(nums[high--], nums[mid]);
    else
      mid++;
  }
}

int main()
{
  fast;
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
      int in;
      cin >> in;
      v.push_back(in);
    }
    sortColors(v);
    for (auto x : v)
      cout << x << " ";

    cout << "\n";
  }

  return 0;
}