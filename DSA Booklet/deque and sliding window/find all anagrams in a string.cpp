#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MAX_CHAR 256

bool comp(int A[], int B[])
{
    for (int i = 0; i < MAX_CHAR; i++)
    {
        if (A[i] != B[i])
            return false;
    }
    return true;
}

vector<int> solve(string text, string patt)
{
    vector<int> res;
    int text_freq[MAX_CHAR] = {0};
    int patt_freq[MAX_CHAR] = {0};
    for (auto ch : patt)
        patt_freq[ch - 'a']++;
    int l = 0, r = 0;
    int ws = min(text.length(), patt.length());
    for (r = 0; r < ws; r++) // applying the window
    {
        text_freq[text[r] - 'a']++;
    }
    if (comp(text_freq, patt_freq))
        res.push_back(0);
    for (; r < text.length(); r++) // extraction
    {
        text_freq[text[r] - 'a']++;
        int l = r - patt.length() + 1;
        text_freq[text[l - 1] - 'a']--; // shrink
        if (comp(text_freq, patt_freq))
            res.push_back(l);
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
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}