#include <bits/stdc++.h>
using namespace std;
class Heap
{
    int heapsize = 0; // number of elements in heap
public:
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    void heapify(vector<int> &A, int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int greatest = i;
        if (left < heapsize && A[left] > A[greatest])
            greatest = left;
        if (right < heapsize && A[right] > A[greatest])
            greatest = right;
        if (greatest != i)
        {
            swap(A[i], A[greatest]);
            heapify(A, greatest);
        }
    }
    // From heap, we can delete only root ie largest element, we can't delete any other element
    int Extract_max(vector<int> &A)
    {
        int ans = A[0];
        swap(A[0], A[heapsize - 1]); // A[0]=A[heapsize-1]
        A.pop_back();
        heapsize--;
        heapify(A, 0);
        return ans;
    }
    // direction of adjustments is from root towards leafs in insertion

    // Inserting an element takes O(logn)time
    void insert(vector<int> &A, int key)
    {
        cout << "Insering key " << key << "\n";
        A.push_back(key);
        heapsize++;
        int i = heapsize - 1; // last index after inserting
        while (i > 0 && key > A[parent(i)])
        {
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
    }

    void buildheap(vector<int> &A)
    {
        heapsize = A.size();
        for (int i = (heapsize - 1) / 2; i >= 0; i--)
            heapify(A, i);
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
            heapify(A, 0);
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