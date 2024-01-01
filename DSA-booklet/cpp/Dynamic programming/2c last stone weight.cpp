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
class Solution
{
public:
    void subsetSums(vector<int> &v, int n, int range, vector<int> &possible)
    {

        possible[0] = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int c = v[i];
            for (int x = range; x >= c; x--)
            {
                if (possible[x - c])
                {
                    possible[x] = 1;
                }
            }
        }
    }
    int lastStoneWeightII(vector<int> &arr)
    {
        int n = arr.size();
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            range += arr[i];
        }
        int s1, s2;
        vector<int> possible(range + 1, 0);
        subsetSums(arr, n, range, possible);
        for (int i = range / 2; i >= 0; i--)
        {
            if (possible[i])
            {
                s1 = i;
                s2 = range - s1;
                return s2 - s1;
            }
        }
        return 0;
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
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution solution;
        auto ans = solution.lastStoneWeightII(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}