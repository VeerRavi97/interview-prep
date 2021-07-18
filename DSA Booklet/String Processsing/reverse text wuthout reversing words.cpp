#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
typedef vector<vi> vvi;

string reverseWordsII(string s)
{
    stack<string> st;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (!str.empty())
                st.push(str);
            str = "";
        }
        else
            str += s[i];
    }
    if (!str.empty())
        st.push(str);
    s.clear();
    while (!st.empty())
    {
        string tp = st.top();
        s += tp;
        s += ' ';
        st.pop();
    }
    s.erase(prev(s.end()));
    return s;
}

string reverseWords(string s)
{
    stack<string> st;
    string temp = "";
    string res = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (!temp.empty())
            {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += ' ';
            }
            temp = "";
        }
        else
            temp += s[i];
    }
    if (!temp.empty())
    {
        reverse(temp.begin(), temp.end());
        res += temp;
        res += ' ';
    }
    res.erase(prev(res.end()));
    reverse(res.begin(), res.end());
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
        cin.ignore();
        string str;
        getline(cin, str);
        auto ans = reverseWords(str);
        cout << ans << endl;
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)((double)end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}