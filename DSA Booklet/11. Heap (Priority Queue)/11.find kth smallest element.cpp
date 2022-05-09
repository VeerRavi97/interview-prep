#include <iostream>
#include <vector>
#include <queue>
#include <random>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class Utils
{
public:
    static void random_shuffle(vector<int> &v)
    {
        srand(time(nullptr));
        for (int i = v.size(); i >= 0; i--)
        {
            int start = 0;
            int end = i - 1;
            int random_idx = start + rand() % (end - start + 1);
            // rand() % i;
            swap(v[random_idx], v[i]);
        }
    }
};

int kthsmallest_minheap(vi &v, int k)
{
    priority_queue<int, vi, greater<int>> pq; // min heap
    for (auto x : v)
        pq.push(x);
    int ans = -1;
    int i = 0;
    if (k > v.size())
        return -1;
    while (i < k - 1)
    {
        i++;
        pq.pop();
    }
    ans = pq.top();
    return ans;
}
int kthsmallest_maxheap(vi &v, int k)
{
    priority_queue<int> pq; // max heap
    for (int i = 0; i < k; i++)
        pq.push(v[i]);
    int ans = -1;
    if (k > v.size())
        return -1;
    for (int i = k; i < v.size(); i++)
    {
        if (pq.top() > v[i])
        {
            pq.pop();
            pq.push(v[i]);
        }
    }
    ans = pq.top();
    return ans;
}
int partition(vector<int> &nums, int start, int end)
{
    int pivot = nums[end];
    int j = start - 1;
    for (int i = start; i < end; i++)
    {
        if (nums[i] < pivot)
        {
            swap(nums[i], nums[++j]);
        }
    }
    swap(nums[end], nums[++j]);
    return j;
}

int randompartition(vi &v1, int start, int end)
{
    int n = end - start;
    int random = start + rand() % n;
    swap(v1[random], v1[end]);
    int pindex = partition(v1, start, end);
    return pindex;
}

int quickSelect(vector<int> &nums, int start, int end, int k)
{
    if (start <= end)
    {
        int p_idx = partition(nums, start, end);
        // int leftLL = p_idx - start + 1;
        if (p_idx == k)
            return nums[p_idx];
        else if (k < p_idx)
            return quickSelect(nums, start, p_idx - 1, k);
        else
            return quickSelect(nums, p_idx + 1, end, k);
    }
    return -1;
}
int findKthLargest(vector<int> &nums, int k)
{
    if (nums.size() == 0)
        return 0;
    Utils::random_shuffle(nums);
    int ans = quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    return ans;
}

int main()
{
    srand(time(NULL));
    vi v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }
    for (int k = 0; k < n; k++)
    {
        cout << kthsmallest_minheap(v, k + 1) << " ";
    }
    cout << "\n";
    for (int k = 0; k < n; k++)
    {
        cout << kthsmallest_maxheap(v, k + 1) << " ";
    }
    cout << "\n";

    return 0;
}