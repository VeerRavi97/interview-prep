#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
int partition(vi &v1, int start, int end)
{
    int pindex = start - 1;
    int i = 0;
    int pivot = v1[end];
    for (i = start; i < end; i++)
    {
        if (v1[i] <= pivot)
        {
            swap(v1[++pindex], v1[i]);
        }
    }
    swap(v1[++pindex], v1[end]);
    return pindex;
}
int randompartition(vi &v1, int start, int end)
{
    int n = end - start;
    srand(time(NULL));
    int random = start + rand() % n;
    // cout << "random " << random << "\n";
    swap(v1[random], v1[end]);
    int pindex = partition(v1, start, end);
    return pindex;
}

int randomizedquickselect(vi &v1, int start, int end, int k)
{

    if (k <= end - start + 1)
    {

        int pindex = partition(v1, start, end);
        // cout << "sorted " << pindex << " " <<  v1[pindex] << "\n";

        int leftsublength = pindex - start + 1; // A[start,pindex],length of left subarray
        if (leftsublength == k)
        {
            return v1[pindex];
        }
        else if (leftsublength > k)
        { // more smaller elements in left subarray
            return randomizedquickselect(v1, start, pindex - 1, k);
        }
        else
        {
            int remk = k - leftsublength;
            return randomizedquickselect(v1, pindex + 1, end, remk);
        }
    }
    return -1;
}

int main()
{
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

    for (int k = 0; k < n; k++)
    {
        vi v1(v);
        cout << randomizedquickselect(v1, 0, n - 1, k + 1) << " ";
    }

    return 0;
}