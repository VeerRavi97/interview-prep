#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

string formatter(string local_name)
{
    string res = "";
    for (auto &ch : local_name)
    {
        if (ch == '.')
            continue;
        if (ch == '+')
            return res;
        res += ch;
    }
    return res;
}

int solve(vector<string> &emails)
{
    set<string> uniqueEmails;
    for (auto &email : emails)
    {
        int end = email.find("@");
        string local = email.substr(0, end);
        string domain = email.substr(end);
        local = formatter(local);
        string new_email = local + domain;
        uniqueEmails.insert(new_email);
    }
    return uniqueEmails.size();
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
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = solve(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}