

#include <iostream>
#include <vector>
// Sorting : O(nlogn + K)
// Max Heap : O(n) + O(klog(n)
// Min heap: O(k) + O((n-k)logk)
// Quick Select: O(n)

using namespace std;

// 1 3 4 4 6: 3 largest : 4

// 4 3 6 4 1

// 7, 10, 2, 3, 20, 15, 25, 4

// 4 : pivot

int partition(vector<int> &list, int start, int end)
{                           //  1, 3, 6, 4, 4.     3,4,4,6
    int pIndex = start - 1; // -1
    int pivot = list[end];  // 1
    for (int j = start; j < end - 1; j++)
    {
        if (list[j] <= pivot)
            swap(list[++pIndex], list[j]);
    }
    swap(list[++pIndex], list[end]);
    return pIndex;
}
int quickSelect(vector<int> &list, int k, int start, int end)
{

    if (start < end)
    {
        int partitionIdx = partition(list, start, end); // 0, // 2
        // cout << partitionIdx << " ";
        int leftPartLength = partitionIdx - start + 1;
        if (leftPartLength == k)
            return list[partitionIdx]; // 2+1=3,
        if (k < leftPartLength)
            return quickSelect(list, k, start, partitionIdx - 1);
        else
            return quickSelect(list, k - leftPartLength, partitionIdx + 1, end); // 1, 4
    }
    return -1;
}

int getKthLargestElement(vector<int> &list, int k)
{
    // add your logic here
    int n = list.size();
    return quickSelect(list, k, 0, n - 1);
}

int main()
{

    vector<int> list = {4, 3, 6, 4, 1};
    cout << getKthLargestElement(list, 3);
}

// k/2, k