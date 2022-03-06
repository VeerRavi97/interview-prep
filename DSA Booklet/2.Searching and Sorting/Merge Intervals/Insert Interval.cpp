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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> mergedIntervals;
        int n = intervals.size();
        int i = 0;
        while (i < n && intervals[i][1] < newInterval[0])
        {
            mergedIntervals.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        mergedIntervals.push_back(newInterval);

        // Push all remaining 
        while (i < intervals.size())
        {
            mergedIntervals.push_back(intervals[i]);
            ++i;
        }

        return mergedIntervals;
    }
};
int main()
{
    // Driver
}