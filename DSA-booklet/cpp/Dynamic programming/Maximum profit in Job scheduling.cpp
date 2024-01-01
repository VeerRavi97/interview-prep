#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Job
{
public:
    int startTime;
    int endTime;
    int profit;
    Job(int startTime, int endTime, int profit) : startTime(startTime), endTime(endTime), profit(profit) {}
};

bool comp(Job &a, Job &b)
{
    return (a.endTime < b.endTime);
}

int binarySearch(vector<Job> &jobs, int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].endTime <= jobs[index].startTime)
        {
            if (jobs[mid + 1].endTime <= jobs[index].startTime)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}

int searchNonConflicting(vector<Job> &jobs, int idx)
{
    int j = idx - 1;
    while (j >= 0)
    {
        if (jobs[idx].startTime >= jobs[j].endTime)
            return j;
        j--;
    }
    return -1;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<Job> jobs;
    for (int i = 0; i < n; i++)
    {
        Job job(startTime[i], endTime[i], profit[i]);
        jobs.push_back(job);
    }
    sort(jobs.begin(), jobs.end(), comp);
    sort(endTime.begin(), endTime.end());
    vector<int> dp(n + 1, 0);
    dp[0] = jobs[0].profit;

    for (int i = 1; i < n; i++)
    {
        int s = jobs[i].startTime;
        int e = jobs[i].endTime;
        int p = jobs[i].profit;

        // exclude
        int excludingProfit = dp[i - 1];

        // include
        int includingProfit = p;
        int idx = upper_bound(endTime.begin(), endTime.end(), s) - endTime.begin();
        idx -= 1;
        if (idx != -1)
            includingProfit += dp[idx];

        dp[i] = max(includingProfit, excludingProfit);
    }

    return dp[n - 1];
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    auto ip = freopen("input.txt", "r", stdin);
    auto op = freopen("output.txt", "w", stdout);
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
        int n;
        cin >> n;
        vector<int> start(n, 0);
        vector<int> end(n, 0);
        vector<int> profit(n, 0);
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        for (int i = 0; i < n; i++)
            cin >> profit[i];

        auto ans = jobScheduling(start, end, profit);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}