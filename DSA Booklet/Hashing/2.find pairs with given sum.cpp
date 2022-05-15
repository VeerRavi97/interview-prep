#include <iostream>
#include <unordered_map>
#include <vector>
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
int CountPairs(vector<int> &v, int n, int target)
{
    unordered_map<int, int> mp;
    long long count = 0;
    for (auto first : v)
    {
        int second = target - first;
        count += mp[second];
        mp[first]++;
    }

    return count;
}
vector<int> twoSum(vector<int> &nums, int target)
{

    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(make_pair(nums[i], i));
    }

    vector<int> res(2, -1);
    int left = 0;
    int right = nums.size() - 1;
    sort(v.begin(), v.end());
    while (left < right)
    {
        int sum = v[left].first + v[right].first;
        if (sum == target)
        {
            res[0] = v[left].second;
            res[1] = v[right].second;
            return res;
        }
        else if (sum > target)
            right--;
        else
            left++;
    }

    return res;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int second = target - first;
        if (mp.count(second))
        {
            res.push_back(i);
            res.push_back(mp[second]);
        }

        mp.insert({first, i});
    }
    return res;
}

int main()
{
    clock_t start = clock();
    file_io();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int in;
            cin >> in;
            v.push_back(in);
        }
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}

// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1