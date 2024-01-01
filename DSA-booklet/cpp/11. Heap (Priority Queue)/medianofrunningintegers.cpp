#include <iostream>
using namespace std;
typedef long long ll;
void swap(ll &a, ll &b)
{
    ll temp = a;
    a = b;
    b = temp;
}
class max_heap
{
public:
    ll n = 0; // number of elements in max_heap
    ll parent(ll i)
    {
        return (i - 1) / 2;
    }

    void heapify(ll A[], ll i)
    {
        ll left = 2 * i + 1;
        ll right = 2 * i + 2;
        ll greatest = i;
        if (left < n && A[left] > A[greatest])
            greatest = left;
        if (right < n && A[right] > A[greatest])
            greatest = right;
        if (greatest != i)
        {
            swap(A[i], A[greatest]);
            heapify(A, greatest);
        }
    }
    ll find_max(ll A[])
    {
        ll ans = A[0];
        return ans;
    }
    ll delete_max(ll A[])
    {
        ll ans = A[0];
        swap(A[0], A[n - 1]); // A[0]=A[heapsize-1]
        // A.pop_back();
        n--;
        heapify(A, 0);
        return ans;
    }
    void insert(ll A[], ll key)
    {
        // cout << "Inserting key in to maxheap " << key << "\n";
        A[n++] = key;
        ll i = n - 1; // last index after inserting
        while (i > 0 && key > A[parent(i)])
        {
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
    }
    void display(ll A[])
    {
        cout << "Heap is : ";
        for (ll i = 0; i < n; i++)
            cout << A[i] << " ";

        cout << "\n";
    }
};
class min_heap
{

public:
    ll m = 0; // number of elements in max_heap
    ll parent(ll i)
    {
        return (i - 1) / 2;
    }

    void heapify(ll A[], ll i)
    {
        ll left = 2 * i + 1;
        ll right = 2 * i + 2;
        ll smallest = i;
        if (left < m && A[left] < A[smallest])
            smallest = left;
        if (right < m && A[right] < A[smallest])
            smallest = right;
        if (smallest != i)
        {
            swap(A[i], A[smallest]);
            heapify(A, smallest);
        }
    }
    ll find_min(ll A[])
    {
        ll ans = A[0];
        return ans;
    }
    void delete_min(ll A[])
    {
        ll ans = A[0];
        swap(A[0], A[m - 1]); // A[0]=A[heapsize-1]
        // A.pop_back();
        m--;
        heapify(A, 0);
    }
    void insert(ll A[], ll key)
    {
        // cout << "Inserting key into min heap " << key << "\n";
        A[m++] = key;
        ll i = m - 1; // last index after inserting
        while (i > 0 && key < A[parent(i)])
        {
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
    }
    // void display(ll A[]){
    //     cout <<  "Heap is : ";
    //     for(ll i=0;i<m;i++)
    //     cout << A[i] << " ";

    //   cout << "\n";
    // }
};
int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        ll A[n + 1];
        for (ll i = 0; i < n; i++)
            cin >> A[i];
        max_heap h1;
        min_heap h2;
        ll maxheap[n + 1];
        ll minheap[n + 1];
        double med = A[0];
        h1.insert(maxheap, A[0]);
        // h1.display(maxheap);
        printf("%0.1f\n", med);

        for (ll i = 1; i < n; i++)
        {
            double x = A[i];
            ll sz1 = h1.n;
            ll sz2 = h2.m;
            //    cout << " elem " << x << " sz1 " << sz1 << " sz2 " << sz2 << "\n";
            if (sz1 > sz2)
            {
                if (x < med)
                {
                    h2.insert(minheap, h1.find_max(maxheap));
                    h1.delete_max(maxheap);
                    h1.insert(maxheap, x);
                }
                else
                {
                    h2.insert(minheap, x);
                }

                med = (h1.find_max(maxheap) + h2.find_min(minheap)) / 2.0;
            }
            else if (sz2 > sz1)
            {
                if (x > med)
                {
                    h1.insert(maxheap, h2.find_min(minheap));
                    h2.delete_min(minheap);
                    h2.insert(minheap, x);
                }
                else
                {
                    h1.insert(maxheap, x);
                }

                med = (h1.find_max(maxheap) + h2.find_min(minheap)) / 2.0;
            }
            else
            {
                if (x < med)
                {
                    h1.insert(maxheap, x);
                    med = h1.find_max(maxheap);
                }
                else
                {
                    h2.insert(minheap, x);
                    med = h2.find_min(minheap);
                }
            }
            //  cout << "displaying maxheap " << "\n";
            //   h1.display(maxheap);
            //   cout << "\n";
            //    cout << "displaying minheap " << "\n";
            //   h2.display(minheap);
            //   cout << "\n";
            printf("%0.1f\n", med);
        }
    }
}