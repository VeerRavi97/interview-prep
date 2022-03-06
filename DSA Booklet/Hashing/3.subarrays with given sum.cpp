// https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    int pre = 0;
    mp[0] = 1;
    int len = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        pre += nums[i];
        if (mp.count(pre - k))
            len += mp[pre - k];
        mp[pre]++;
    }
    return len;
}

int lenOfLongSubarr(vi &A, int N, int K)
{
    unordered_map<int, int> mp;
    int pre = 0;
    mp[0] = -1;
    int len = 0;
    for (int i = 0; i < A.size(); i++)
    {
        pre += A[i];
        if (mp.count(pre - K))
            len = max(len, i - mp[pre - K]);
        if (!mp.count(pre))
            mp[pre] = i;
    }
    return len;
}
void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
        int n, k;
        cin >> n >> k;
        vi v;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
        cout << "count " << subarraySum(v, k) << ", ";
        cout << "longest " << lenOfLongSubarr(v, n, k) << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}

/*
6
20 30
1 12 18 13 8 -2 12 -1 -10 6 3 -14 0 4 10 0 -7 3 -12 18
3 2
1 1 1
3 3
1 2 3
6 15
10 5 2 7 1 9
3 6
-1 2 3
17 15
-13 0 6 15 16 2 15 -12 17 -16 0 -3 19 -3 2 -9 -6



count 2, longest 5
count 2, longest 2
count 2, longest 2
count 2, longest 4
count 0, longest 0
count 4, longest 5


Executed In: 0.006s



*/