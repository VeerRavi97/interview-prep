
#include <bits/stdc++.h>
using namespace std;

class SolutionI
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 0;
        int m;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m)
                cnt++;
            else if (cnt == 0)
            {
                m = nums[i];
                cnt = 1;
            }
            else
                cnt--;
        }
        cnt = 0;
        for (int el : nums)
        {
            if (el == m)
                cnt++;
        }
        if (cnt > nums.size() / 2)
            return m;
        return -1;
    }
};

class SolutionII
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int cnt1 = 0, cnt2 = 0;
        int m1, m2;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == m1)
                cnt1++;
            else if (nums[i] == m2)
                cnt2++;
            else if (cnt1 == 0)
            {
                m1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0)
            {
                m2 = nums[i];
                cnt2 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> res;
        cnt1 = 0;
        cnt2 = 0;
        for (int el : nums)
        {
            if (el == m1)
                cnt1++;
            if (el == m2)
                cnt2++;
        }
        if (cnt1 > nums.size() / 3)
            res.push_back(m1);
        if (cnt2 > nums.size() / 3)
            res.push_back(m2);
        return res;
    }
};