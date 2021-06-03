/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int first_occurrence(int arr[], int n, int x)
    {
        int start = 0;
        int end = n - 1;
        int idx = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (arr[mid] == x)
            {
                idx = mid;
                end = mid - 1;
            }
            else if (x > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return idx;
    }
    int last_occurrence(int arr[], int n, int x)
    {
        int start = 0;
        int end = n - 1;
        int idx = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (arr[mid] == x)
            {
                idx = mid;
                start = mid + 1;
            }
            else if (x > arr[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return idx;
    }
    int lower_boundCC(int arr[], int n, int x)
    {
        int start = 0;
        int end = n;
        int idx = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (arr[mid] == x)
            {
                idx = mid;
                end = mid - 1;
            }
            else if (arr[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                idx = mid;
                end = mid - 1;
            }
        }
        return idx;
    }
    int upper_boundCC(int arr[], int n, int x)
    {
        int start = 0;
        int end = n;
        int idx = -1;
        while (start <= end)
        {
            int mid = start + ((end - start) >> 1);
            if (arr[mid] == x)
            {
                idx = mid + 1;
                start = mid + 1;
            }
            else if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                idx = mid;
                end = mid - 1;
            }
        }
        return idx;
    }
    int count(int arr[], int n, int x)
    {
        int first = first_occurrence(arr, n, x);
        int second = last_occurrence(arr, n, x);
        if (first == -1 || second == -1)
            return 0;
        return second - first + 1;
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int nx;
        cin >> nx;
        for (int i = 0; i < nx; i++)
        {
            cin >> x;
            auto first = ob.first_occurrence(arr, n, x);
            auto last = ob.last_occurrence(arr, n, x);
            auto cnt1 = ob.count(arr, n, x);
            auto lower = ob.lower_boundCC(arr, n, x);
            auto upper = ob.upper_boundCC(arr, n, x);
            auto cnt2 = upper - lower;
            cout << first << " " << last << " " << cnt1 << " " << lower << " " << upper << " " << cnt2 << "\n";
        }
    }
    return 0;
}
