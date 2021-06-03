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

int findpivotindex(vi &v)
{
  int n = v.size();
  if (v[0] < v[n - 1])
    return 0;
  int start = 0;
  int end = n - 1;
  while (start <= end)
  {

    int mid = (start + end) / 2;
    //   cout << start <<  " " << end << " " << mid << "\n";
    if (v[mid] > v[mid + 1])
      return mid + 1;
    else if (v[0] < v[mid])
      start = mid + 1;
    else
    {
      end = mid;
    }
  }
  return -1;
}
int binarysearch_asc(vi &v, int start, int end, int num)
{
  while (start <= end)
  {

    int mid = (start + end) / 2;
    if (v[mid] == num)
    {
      return mid;
    }
    else if (v[mid] > num)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }
  // cout << "not found " << "\n";
  return -1;
}

int search(vi &v, int num)
{
  int pindex = findpivotindex(v);
  // cout << pindex << "\n";
  int start = 0;
  int end = v.size() - 1;
  if (pindex == 0)
    return binarysearch_asc(v, 0, end, num); // array is not rotated
  if (v[pindex] == num)
    return pindex;
  if (v[0] < v[pindex] && num >= v[0])
    return binarysearch_asc(v, 0, pindex - 1, num);
  else
    return binarysearch_asc(v, pindex + 1, end, num);
}
// 80 90             10 20 30 40 50 60 70

// Size of the Array - n
// No of Rotations - r
// r < n
// Optimal way to find r

//30 40 50 60 70 80 90 10 20
// 0  1  2 3  4  5  6  7   8
int rotationCount(int arr[], int n)
{
  if (arr[0] < arr[n - 1])
    return 0; // array already sorted
  int start = 0;
  int end = n - 1;
  int temp_ans = -1;
  while (start <= end)
  {
    int mid = start + ((end - start) >> 1);
    if (arr[mid - 1] > arr[mid])
    {
      temp_ans = mid;
      break;
    }
    else if (arr[0] > arr[mid])
    {
      start = mid + 1;
    }
    else
    {
      end = mid;
    }
  }
  return n - temp_ans; // 9-7 = 2 rotation count
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
    vi v;
    for (int i = 0; i < n; i++)
    {
      int in;
      cin >> in;
      v.push_back(in);
    }
    int num;
    cin >> num;
    int index = search(v, num);
    cout << index << "\n";
  }

  return 0;
}