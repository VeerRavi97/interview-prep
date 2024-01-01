#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1e9 + 7
#define INF 1e18
#define endl '\n'
#define all(c) c.begin(), c.end()
#define DEBUG printf("")
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
int magnitude(int n)
{
    return abs(n);
}

vector<int> solve(vector<int> &asteroids)
{

    stack<int> st;
    for (auto asteroid : asteroids)
    {
        if (asteroid > 0)
        {
            st.push(asteroid);
        }
        else
        {
            // can push or can't push
            int exploded = false;
            while (!st.empty() && st.top() > 0)
            {
                int magA = -asteroid;
                int magB = st.top();
                if (magA < magB)
                {
                    exploded = true; // kicked
                    break;
                }
                else if (magA == magB)
                {
                    st.pop();
                    exploded = true; // diminished
                    break;
                }
                else
                {
                    st.pop();
                    exploded = false; // swallowed
                }
            }
            if (!exploded)
                st.push(asteroid);
        }
    }
    vector<int> output(st.size(), 0);
    int itr = st.size() - 1;
    while (!st.empty())
    {
        output[itr--] = st.top();
        st.pop();
    }
    return output;
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
        vi v(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        solve(v);
    }

    clock_t end = clock();
#ifndef ONLINE_JUDGE
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    cout << "\n\nExecuted In: " << cpu_time_used << "s" << endl;
#endif
}