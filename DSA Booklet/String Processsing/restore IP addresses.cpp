#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#define ll long long
#define MOD 10000000007
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution
{
    vector<string> IpAddresses;
    int n;
    string str;

public:
    bool isValid(string s)
    {
        if (s.length() > 3)
            return false;
        if (s[0] == '0' && s.length() > 1)
            return false;
        int num;
        stringstream ss(s);
        ss >> num;
        if (num > 255)
            return false;
        return true;
    }
    void helper(string runningStr, int dotsleft, int idx)
    {
        if (dotsleft == 0)
        {
            string wordTobeAppended = str.substr(idx);
            if (isValid(wordTobeAppended))
            {
                runningStr += '.';
                runningStr += wordTobeAppended;
                this->IpAddresses.push_back(runningStr);
            }
            return;
        }
        int max_pos = min(n - 1, idx + 3);
        for (int j = idx; j < max_pos; j++)
        {
            string wordTobeAppended = str.substr(idx, j - idx + 1);
            int pos = runningStr.length();
            int len = wordTobeAppended.length();
            if (isValid(wordTobeAppended))
            {
                if (dotsleft == 3)
                {
                    runningStr += wordTobeAppended;
                    helper(runningStr, dotsleft - 1, j + 1);
                    runningStr.erase(pos, len);
                }
                else
                {
                    runningStr += '.';
                    runningStr += wordTobeAppended;
                    helper(runningStr, dotsleft - 1, j + 1);
                    runningStr.erase(pos, len + 1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        this->n = s.length();
        this->str = s;
        if (n < 4 || n > 12)
            return IpAddresses;
        helper("", 3, 0);
        return IpAddresses;
    }
};

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
        string str;
        cin >> str;
        Solution solution;
        auto ans = solution.restoreIpAddresses(str);
        for (auto &IpAddress : ans)
            cout << IpAddress << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}