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

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());
        vector<int> runningInterval = intervals[0];
        int n = intervals.size();
        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] > runningInterval[1])
            {
                mergedIntervals.push_back(runningInterval);
                runningInterval = intervals[i];
            }
            else
            {
                runningInterval[1] = max(runningInterval[1], intervals[i][1]);
            }
        }
        mergedIntervals.push_back(runningInterval);
        return mergedIntervals;
    }
};
int main()
{
    // Driver
}