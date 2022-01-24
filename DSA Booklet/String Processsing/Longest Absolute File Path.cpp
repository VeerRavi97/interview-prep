#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int doSegment(char *sentence)
{
    std::stringstream ss(sentence);
    std::string to;

    if (sentence != NULL)
    {
        while (std::getline(ss, to, '\n'))
        {
            cout << to << endl;
        }
    }

    return 0;
}

int countOccurences(string txt, string patt)
{
    int occurrences = 0;
    int start = 0;
    int end = txt.find(patt);
    while (end != -1)
    {
        ++occurrences;
        start = end + patt.length();
        end = txt.find(patt, start);
    }
    return occurrences;
}

int lengthLongestPath(string input)
{
    int res = INT_MIN;
    int start = 0;
    string delim = "\n";
    int end = input.find(delim);
    string token;
    unordered_map<int, int> mp;
    mp[-1] = 0;

    while (end != -1)
    {
        token = input.substr(start, (end - start));
        int lvl = countOccurences(token, "\t");
        int len = token.length();
        mp[lvl] = mp[lvl - 1] + len - (lvl);
        if (token.find('.') != -1)
        {
            res = max(res, mp[lvl] + lvl);
        }
        start = end + delim.length();
        end = input.find(delim, start);
    }
    token = input.substr(start, (end - start));
    int lvl = countOccurences(token, "\t");
    int len = token.length();
    mp[lvl] = mp[lvl - 1] + len - lvl;
    if (token.find('.') != -1)
    {
        res = max(res, mp[lvl] + lvl);
    }
    return res != INT_MIN ? res : 0;
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
        auto ans = lengthLongestPath(str);
        cout << ans << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}



/*



dir
⟶ subdir1
⟶ ⟶ file1.ext
⟶ ⟶ subsubdir1
⟶ subdir2
⟶ ⟶ subsubdir2
⟶ ⟶ ⟶ file2.ext


"dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"









*/