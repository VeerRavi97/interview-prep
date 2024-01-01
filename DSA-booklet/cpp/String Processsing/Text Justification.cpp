#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define MOD 1e9 + 7
#define all(c) c.begin(), c.end()
#define endl '\n'
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;
void middleJustify(vs &res, vs &words, int l, int r, int totalSpaces)
{
    int spaceCount = (r - l);
    int spaces = totalSpaces / spaceCount;
    int extraSpaces = totalSpaces % spaceCount;
    string temp = words[l];
    for (int k = l + 1; k <= r; k++)
    {
        int spacesToApply = spaces + (extraSpaces-- > 0 ? 1 : 0);
        for (int cnt = 0; cnt < spacesToApply; cnt++)
            temp += " ";
        temp += words[k];
    }
    res.push_back(temp);
}

void leftJustify(vs &res, vs &words, int l, int r, int totalSpaces)
{
    int spaceCount = (r - l);
    int spacesOnRight = totalSpaces - spaceCount;
    string temp = words[l];
    for (int k = l + 1; k <= r; k++)
    {
        temp += " ";
        temp += words[k];
    }
    for (int cnt = 0; cnt < spacesOnRight; cnt++)
        temp += " ";

    res.push_back(temp);
}

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    int n = words.size();
    vector<string> res;
    int l = 0, r = 0;
    int charsCount = 0;
    for (r = 0; r < n; r++)
    {
        int len = words[r].length();
        charsCount += len;
        int wordsCount = (r - l + 1);
        int spaceCount = wordsCount - 1;
        if (charsCount + spaceCount > maxWidth)
        {
            int delta = maxWidth - (charsCount - len);
            if (l == r - 1)
                leftJustify(res, words, l, l, delta);
            else
                middleJustify(res, words, l, r - 1, delta);
            charsCount = len;
            l = r;
        }
        if (r == n - 1)
        {
            int delta = maxWidth - charsCount;
            leftJustify(res, words, l, r, delta);
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
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int maxWidth;
        cin >> maxWidth;
        auto ans = fullJustify(v, maxWidth);
        for (auto &str : ans)
            cout << str << endl;
    }
    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = (double)((double)end - start) / CLOCKS_PER_SEC;
    cout << "Executed in " << cpu_time_used << "s" << endl;
#endif
}

/*

Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
*/