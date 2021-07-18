#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_CHAR 26

bool comp(int A[], int B[])
{
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

string solve(string text, string patt)
{
    string res = "";
    int text_freq[256] = {0};
    int patt_freq[256] = {0};
    if (patt.length() > text.length())
        return res;
    for (auto ch : patt)
        patt_freq[ch]++;
    int l = 0, r = 0;
    int cnt = 0;
    int min_len = INT_MAX;
    int start_idx = r;
    for (; r < text.length(); r++) // expansion
    {
        char ch = text[r];
        text_freq[ch]++;
        if (patt_freq[ch] != 0 && text_freq[ch] <= patt_freq[ch])
            cnt++;
        if (cnt == patt.length())
        {
            while (patt_freq[text[l]] == 0 || (text_freq[text[l]] > patt_freq[text[l]]))
            {
                text_freq[text[l]]--;
                l++;
            }
            if (min_len > (r - l + 1))
            {
                min_len = r - l + 1;
                start_idx = l;
                res = text.substr(start_idx, min_len);
            }
        }
    }
    return res;
}

void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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
        string text, patt;
        cin >> text >> patt;
        auto ans = solve(text, patt);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}