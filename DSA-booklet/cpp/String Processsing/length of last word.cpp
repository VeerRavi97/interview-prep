#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int lengthOfLastWord(string s)
{
    int res = 0;
    int counter = 0;
    for (auto ch : s)
    {
        if (ch == ' ' && counter != 0)
        {
            res = counter;
            counter = 0;
        }
        else if (ch != ' ')
            counter++;
    }
    if (counter != 0)
        res = counter;
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
    cin.ignore();
    while (tc--)
    {
        string str;
        getline(cin, str);
        auto ans = lengthOfLastWord(str);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}