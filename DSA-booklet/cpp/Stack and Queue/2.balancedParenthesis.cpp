#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
typedef vector<int> vi;
void file_io()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
bool isMatching(char ch1, char ch2)
{
    if (ch1 == ')')
        return (ch2 == '(');
    if (ch1 == ']')
        return (ch2 == '[');
    if (ch1 == '}')
        return (ch2 == '{');
    return false;
}

bool check(string &str)
{
    stack<char> s;
    for (auto ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            if (s.empty() || !isMatching(ch, s.top()))
                return false;
            s.pop();
        }
    }
    return (s.empty() == true);
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
        cout << check(str) << "\n";
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << endl;
#endif
}