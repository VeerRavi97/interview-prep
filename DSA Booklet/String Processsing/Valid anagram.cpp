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
bool isAnagram(string s, string t)
{
    string s_id = generateID(s);
    string t_id = generateID(t);
    if (s_id == t_id)
        return true;
    return false;
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
        string s, t;
        cin >> s >> t;
        auto ans = isAnagram(s, t);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}