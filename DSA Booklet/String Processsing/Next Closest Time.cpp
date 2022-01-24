#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void breakDown(vector<int> &v, int minutes)
{
    v[0] = minutes / 60 / 10;
    v[1] = minutes / 60 % 10;
    v[2] = minutes % 60 / 10;
    v[3] = minutes % 60 % 10;
}

string formatted(vector<int> &v)
{
    string time = "HH:MM";
    time[0] = v[0] + '0';
    time[1] = v[1] + '0';
    time[3] = v[2] + '0';
    time[4] = v[3] + '0';
    return time;
}

string nextClosestTime(string time)
{
    string res = "";
    string hour = time.substr(0, 2);
    string minute = time.substr(3);
    stringstream ss1(hour), ss2(minute);
    int hr, mn;
    ss1 >> hr;
    ss2 >> mn;
    int minutes = hr * 60 + mn;
    set<int> digits;
    for (auto &ch : time)
    {
        if (ch != ':')
            digits.insert(ch - '0');
    }
    while (true)
    {
        minutes = (minutes + 1) % (24 * 60);
        vector<int> dig(4, 0);
        breakDown(dig, minutes);
        bool isValid = true;
        for (int &itr : dig)
        {
            if (digits.find(itr) == digits.end())
            {
                isValid = false;
            }
        }
        if (isValid)
        {
            return formatted(dig);
        }
    }

    return res;
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
        string str;
        cin >> str;
        auto ans = nextClosestTime(str);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}