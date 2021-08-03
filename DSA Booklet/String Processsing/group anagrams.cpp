#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

string generateID(string str)
{
    vector<int> freq(26, 0);
    for (auto ch : str)
        freq[ch - 'a']++;
    string id = "";
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            id += to_string(freq[i]);
            id += (i + 'a');
        }
    }
    return id;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto str : strs)
    {
        string id = generateID(str);
        mp[id].push_back(str);
    }
    vector<vector<string>> res;
    for (auto v : mp)
    {
        res.push_back(v.second);
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
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        auto ans = groupAnagrams(v);
        for (auto v : ans)
        {
            for (auto x : v)
                cout << x << " ";
            cout << endl;
        }
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}