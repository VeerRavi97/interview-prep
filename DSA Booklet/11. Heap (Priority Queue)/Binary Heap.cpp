#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int heapsize = 0; // number of elements in heap
public:
    int parentOf(int idx) { return (idx - 1) >> 1; }
    int leftOf(int idx) { return (idx << 1) + 1; }

    void bubbleDown(vector<int> &A, int idx)
    {
        int left = leftOf(idx);
        int right = left + 1;
        int max_idx = idx;
        if (left < heapsize && A[left] > A[max_idx])
            max_idx = left;
        if (right < heapsize && A[right] > A[max_idx])
            max_idx = right;
        if (max_idx != idx)
        {
            swap(A[idx], A[max_idx]);
            bubbleDown(A, max_idx);
        }
    }

    void bubbleUp(vector<int> &A, int idx)
    {
        while (idx > 0 && A[idx] > A[parentOf(idx)])
        {
            swap(A[idx], A[parentOf(idx)]);
            idx = parentOf(idx);
        }
    }

    // From heap, we can delete only root ie largest element, we can't delete any other element
    int Extract_max(vector<int> &A)
    {
        int ans = A[0];
        swap(A[0], A[heapsize - 1]); // A[0]=A[heapsize-1]
        A.pop_back();
        heapsize--;
        bubbleDown(A, 0);
        return ans;
    }

    int getMax(vector<int> &A)
    {
        if (heapsize > 0)
            return A[0];
        return -1;
    }
    // direction of adjustments is from root towards leafs in insertion

    // Inserting an element takes O(logn)time
    void insert(vector<int> &A, int key)
    {
        cout << "Inserting key " << key << "\n";
        A.push_back(key);
        int last = heapsize - 1;
        heapsize++;
        bubbleUp(A, last);
    }

    void buildheap(vector<int> &A)
    {
        heapsize = A.size();
        for (int i = ((heapsize - 1) >> 1) - 1; i >= 0; i--)
            bubbleDown(A, i);
    }

    void display(vector<int> &A)
    {
        cout << "Heap is : ";
        for (auto x : A)
            cout << x << " ";

        cout << "\n";
    }

    void heapsort(vector<int> &A)
    {
        for (int i = heapsize - 1; i > 0; i--)
        {

            swap(A[0], A[i]);
            heapsize--;
            bubbleDown(A, 0);
        }
    }
};



int main()
{

    Heap h;
    vector<int> A;
    h.insert(A, 10);
    h.display(A);
    h.insert(A, 20);
    h.display(A);
    h.insert(A, 30);
    h.display(A);
    h.insert(A, 25);
    h.display(A);
    cout << "max : " << h.Extract_max(A) << "\n";
    h.display(A);
    cout << "max : " << h.Extract_max(A) << "\n";
    h.display(A);
    h.insert(A, 5);
    h.display(A);
    h.insert(A, 40);
    h.display(A);
    h.insert(A, 35);
    h.display(A);
    A.clear();
    A = {1, 2, 1, 0, 7, 1, 2, 8, 8, 2};
    h.buildheap(A); // 8822711012
    h.display(A);
    h.heapsort(A);
    h.display(A);

    return 0;
}