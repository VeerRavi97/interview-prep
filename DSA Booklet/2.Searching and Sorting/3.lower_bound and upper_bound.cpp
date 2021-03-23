#include <bits/stdc++.h>
using namespace std;
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define int long long
#define endl '\n'
#define all(c) c.begin(), c.end()

typedef vector<int> vi;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int lower_bound(int arr[], int n, int x)
{
    int start = 0;
    int end = n; // n-1 end of the element+1, since it returns >=
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (x <= arr[mid])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int upper_bound(int arr[], int n, int x)
{
    int start = 0;
    int end = n; // n-1 end of the element+1, since it returns >
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (x < arr[mid])
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}
int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    //IOS;
    int tc;
    // cin >> tc;
    tc = 1;
    while (tc--)
    {
        int arr[] = {1, 2, 2, 4, 4, 5, 5, 6};
        int n = 8;
        int key;
        cin >> key;
        int lb = lower_bound(arr, n, key);
        int ub = upper_bound(arr, n, key);
        int freq = ub - lb;

        cout << lb << " " << ub << " " << freq << "\n";
    }
}