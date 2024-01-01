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

string findCommonBtwStrings(string word1, string word2)
{
    int i = 0, j = 0;
    while (i < word1.length() && j < word2.length())
    {
        if (word1[i] != word2[j])
            break;
        i++;
        j++;
    }
    return word1.substr(0,i);
}

string LCP(vector<string> const &words)
{
    string prefix= words[0];
    for (int i=0;i<words.size();i++) {
        prefix = findCommonBtwStrings(prefix, words[i]);
    }
    return prefix;
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
        auto ans = LCP(v);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}