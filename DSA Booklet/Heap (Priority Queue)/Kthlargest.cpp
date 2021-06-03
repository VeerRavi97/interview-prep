#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
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

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (curr > pq.top())
            {
                pq.pop();
                pq.push(curr);
            }
        }
        return pq.top();
    }
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = nums[end];
        int i = start;
        int j = start - 1;
        for (; i < end; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[++j]);
            }
        }
        swap(nums[end], nums[++j]);
        return j;
    }
    int quickSelect(vector<int> &nums, int start, int end, int k)
    {
        if (start < end)
        {
            int p_idx = partition(nums, start, end);
            if (nums.size() - p_idx == k)
                return nums[p_idx];
            quickSelect(nums, start, p_idx, k);
            quickSelect(nums, p_idx + 1, end, k);
        }
        return -1;
    }
    int findKthLargestII(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;
        random_shuffle(all(nums));
        int ans = quickSelect(nums, 0, nums.size() - 1, k);
        return ans;
    }
};

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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution obj;
        int k;
        cin >> k;
        cout << "Kth Largest Number is" << obj.findKthLargestII(v, k) << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}